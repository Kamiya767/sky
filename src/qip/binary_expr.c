#include <stdlib.h>
#include "dbg.h"
#include "util.h"

#include "node.h"

//==============================================================================
//
// Functions
//
//==============================================================================

//--------------------------------------
// Lifecycle
//--------------------------------------

// Creates an AST node for a binary expression.
//
// operator - The operator used in the expression.
// lhs      - The node on the left-hand side.
// rhs      - The node on the right-hand side.
//
// Returns 0 if successful, otherwise returns -1.
qip_ast_node *qip_ast_binary_expr_create(qip_ast_binop_e operator,
                               qip_ast_node *lhs,
                               qip_ast_node *rhs)
{
    qip_ast_node *node = malloc(sizeof(qip_ast_node)); check_mem(node);
    node->type = QIP_AST_TYPE_BINARY_EXPR;
    node->parent = NULL;
    node->line_no = node->char_no = 0;
    node->generated = false;
    node->generated = false;
    node->binary_expr.operator = operator;
    node->binary_expr.boolean_type_ref = qip_ast_type_ref_create_cstr("Boolean");
    check_mem(node->binary_expr.boolean_type_ref);

    node->binary_expr.lhs = lhs;
    if(lhs != NULL) {
        lhs->parent = node;
    }

    node->binary_expr.rhs = rhs;
    if(rhs != NULL) {
        rhs->parent = node;
    }

    return node;

error:
    qip_ast_node_free(node);
    return NULL;
}

// Frees a binary expression AST node from memory.
//
// node - The AST node to free.
void qip_ast_binary_expr_free(qip_ast_node *node)
{
    if(node->binary_expr.lhs) qip_ast_node_free(node->binary_expr.lhs);
    node->binary_expr.lhs = NULL;

    if(node->binary_expr.rhs) qip_ast_node_free(node->binary_expr.rhs);
    node->binary_expr.rhs = NULL;

    if(node->binary_expr.boolean_type_ref) qip_ast_node_free(node->binary_expr.boolean_type_ref);
    node->binary_expr.boolean_type_ref = NULL;
}

// Copies a node and its children.
//
// node - The node to copy.
// ret  - A pointer to where the new copy should be returned to.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_copy(qip_ast_node *node, qip_ast_node **ret)
{
    int rc;
    check(node != NULL, "Node required");
    check(ret != NULL, "Return pointer required");

    qip_ast_node *clone = qip_ast_binary_expr_create(node->binary_expr.operator, NULL, NULL);
    check_mem(clone);

    rc = qip_ast_node_copy(node->binary_expr.lhs, &clone->binary_expr.lhs);
    check(rc == 0, "Unable to copy binary expression LHS");
    if(clone->binary_expr.lhs) clone->binary_expr.lhs->parent = clone;
    
    rc = qip_ast_node_copy(node->binary_expr.rhs, &clone->binary_expr.rhs);
    check(rc == 0, "Unable to copy binary expression RHS");
    if(clone->binary_expr.rhs) clone->binary_expr.rhs->parent = clone;
    
    *ret = clone;
    return 0;

error:
    qip_ast_node_free(clone);
    *ret = NULL;
    return -1;
}


//--------------------------------------
// Codegen
//--------------------------------------

// Generates LLVM code for a binary expression of type "Int".
//
// node - The binary expression node.
// module - The compilation unit this node is a part of.
// lhs    - The left hand value of the expression.
// rhs    - The right hand value of the expression.
// value  - A pointer to where the LLVM value should be returned.
//
// Returns 0 if successful, otherwise returns -1.
int codegen_int(qip_ast_node *node, qip_module *module, LLVMValueRef lhs,
                LLVMValueRef rhs, LLVMValueRef *value)
{
    LLVMBuilderRef builder = module->compiler->llvm_builder;

    switch(node->binary_expr.operator) {
        case QIP_BINOP_PLUS: {
            *value = LLVMBuildAdd(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_MINUS: {
            *value = LLVMBuildSub(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_MUL: {
            *value = LLVMBuildMul(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_DIV: {
            *value = LLVMBuildSDiv(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_EQUALS: {
            *value = LLVMBuildICmp(builder, LLVMIntEQ, lhs, rhs, "");
            break;
        }
        default: {}
    }
    
    check(*value != NULL, "Unable to codegen Int binary expression");
    return 0;

error:
    *value = NULL;
    return -1;
}

// Generates LLVM code for a binary expression of type "Float".
//
// node - The binary expression node.
// module - The compilation unit this node is a part of.
// lhs    - The left hand value of the expression.
// rhs    - The right hand value of the expression.
// value  - A pointer to where the LLVM value should be returned.
//
// Returns 0 if successful, otherwise returns -1.
int codegen_float(qip_ast_node *node, qip_module *module, LLVMValueRef lhs,
                  LLVMValueRef rhs, LLVMValueRef *value)
{
    LLVMBuilderRef builder = module->compiler->llvm_builder;

    switch(node->binary_expr.operator) {
        case QIP_BINOP_PLUS: {
            *value = LLVMBuildFAdd(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_MINUS: {
            *value = LLVMBuildFSub(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_MUL: {
            *value = LLVMBuildFMul(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_DIV: {
            *value = LLVMBuildFDiv(builder, lhs, rhs, "");
            break;
        }
        case QIP_BINOP_EQUALS: {
            *value = LLVMBuildFCmp(builder, LLVMRealOEQ, lhs, rhs, "");
            break;
        }
        default: {}
    }
    
    check(*value != NULL, "Unable to codegen Float binary expression");
    return 0;

error:
    *value = NULL;
    return -1;
}

// Generates LLVM code for a binary expression of type "Boolean".
//
// node   - The binary expression node.
// module - The compilation unit this node is a part of.
// lhs    - The left hand value of the expression.
// rhs    - The right hand value of the expression.
// value  - A pointer to where the LLVM value should be returned.
//
// Returns 0 if successful, otherwise returns -1.
int codegen_boolean(qip_ast_node *node, qip_module *module, LLVMValueRef lhs,
                    LLVMValueRef rhs, LLVMValueRef *value)
{
    LLVMBuilderRef builder = module->compiler->llvm_builder;

    switch(node->binary_expr.operator) {
        case QIP_BINOP_EQUALS: {
            *value = LLVMBuildICmp(builder, LLVMIntEQ, lhs, rhs, "");
            break;
        }
        default: {
            sentinel("Invalid binary operator for a Boolean value");
        }
    }
    
    check(*value != NULL, "Unable to codegen Boolean binary expression");
    return 0;

error:
    *value = NULL;
    return -1;
}

// Generates LLVM code for a binary expression to check for null.
//
// node   - The binary expression node.
// module - The compilation unit this node is a part of.
// lhs    - The LHS expression.
// value  - A pointer to where the LLVM value should be returned.
//
// Returns 0 if successful, otherwise returns -1.
int codegen_is_null(qip_ast_node *node, qip_module *module, qip_ast_node *lhs,
                    LLVMValueRef *value)
{
    int rc;
    LLVMBuilderRef builder = module->compiler->llvm_builder;

    // Retrieve the alloca.
    LLVMValueRef ptr = NULL;
    rc = qip_ast_node_get_var_pointer(lhs, module, &ptr);
    check(rc == 0, "Unable to find variable pointer");

    switch(node->binary_expr.operator) {
        case QIP_BINOP_EQUALS: {
            *value = LLVMBuildIsNull(builder, LLVMBuildLoad(builder, ptr, ""), "");
            break;
        }
        default: {
            sentinel("Invalid binary operator for null check");
        }
    }
    
    check(*value != NULL, "Unable to codegen null check binary expression");
    return 0;

error:
    *value = NULL;
    return -1;
}


// Recursively generates LLVM code for the binary expression AST node.
//
// node    - The node to generate an LLVM value for.
// module  - The compilation unit this node is a part of.
// value   - A pointer to where the LLVM value should be returned.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_codegen(qip_ast_node *node,
                                qip_module *module,
                                LLVMValueRef *value)
{
    int rc;
    LLVMValueRef lhs = NULL, rhs = NULL;
    
    check(node != NULL, "Node required");
    check(node->type == QIP_AST_TYPE_BINARY_EXPR, "Node type must be 'binary expression'");
    check(module != NULL, "Module required");
    
    // Null checks are a special case.
    if(node->binary_expr.rhs->type == QIP_AST_TYPE_NULL_LITERAL) {
        rc = codegen_is_null(node, module, node->binary_expr.lhs, value);
        check(rc == 0, "Unable to codegen null check");
        return 0;
    }

    // Evaluate left and right hand values.
    rc = qip_ast_node_codegen(node->binary_expr.lhs, module, &lhs);
    check(rc == 0 && lhs != NULL, "Unable to codegen lhs");
    rc = qip_ast_node_codegen(node->binary_expr.rhs, module, &rhs);
    check(rc == 0 && rhs != NULL, "Unable to codegen rhs");

    // Retrieve the last variable reference in a chain to determine the type.
    qip_ast_node *lhs_target_node = node->binary_expr.lhs;
    if(lhs_target_node->type == QIP_AST_TYPE_VAR_REF) {
        rc = qip_ast_var_ref_get_last_member(lhs_target_node, &lhs_target_node);
        check(rc == 0, "Unable to retrieve LHS last member");
    }

    qip_ast_node *rhs_target_node = node->binary_expr.rhs;
    if(rhs_target_node->type == QIP_AST_TYPE_VAR_REF) {
        rc = qip_ast_var_ref_get_last_member(rhs_target_node, &rhs_target_node);
        check(rc == 0, "Unable to retrieve RHS last member");
    }

    // Retrieve types.
    bstring lhs_type_name = NULL, rhs_type_name = NULL;
    rc = qip_ast_node_get_type_name(lhs_target_node, module, &lhs_type_name);
    check(rc == 0, "Unable to retrieve LHS type");
    rc = qip_ast_node_get_type_name(rhs_target_node, module, &rhs_type_name);
    check(rc == 0, "Unable to retrieve RHS type");

    // Cast RHS into the LHS type.
    rc = qip_module_cast_value(module, rhs, rhs_type_name, lhs_type_name, &rhs);
    check(rc == 0 && rhs != NULL, "Unable to cast value");

    // Delegate LLVM IR generation to type-specific function.
    if(biseqcstr(lhs_type_name, "Int")) {
        rc = codegen_int(node, module, lhs, rhs, value);
        check(rc == 0, "Unable to codegen Int");
    }
    else if(biseqcstr(lhs_type_name, "Float")) {
        rc = codegen_float(node, module, lhs, rhs, value);
        check(rc == 0, "Unable to codegen Float");
    }
    else if(biseqcstr(lhs_type_name, "Boolean")) {
        rc = codegen_boolean(node, module, lhs, rhs, value);
        check(rc == 0, "Unable to codegen Boolean");
    }

    check(*value != NULL, "Unable to codegen binary expression");

    bdestroy(lhs_type_name);
    bdestroy(rhs_type_name);
    return 0;

error:
    bdestroy(lhs_type_name);
    bdestroy(rhs_type_name);
    *value = NULL;
    return -1;
}


//--------------------------------------
// Preprocessor
//--------------------------------------

// Preprocesses the node.
//
// node   - The node.
// module - The module that the node is a part of.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_preprocess(qip_ast_node *node, qip_module *module)
{
    check(node != NULL, "Node required");
    check(module != NULL, "Module required");
    
    return 0;

error:
    return -1;
}


//--------------------------------------
// Type
//--------------------------------------

// Returns the type name of the AST node.
//
// node     - The AST node to determine the type for.
// module   - The compilation unit this node is a part of.
// type_ref - A pointer to where the type should be returned.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_get_type(qip_ast_node *node, qip_module *module,
                                 qip_ast_node **type_ref)
{
    int rc;
    check(node != NULL, "Node required");
    check(node->type == QIP_AST_TYPE_BINARY_EXPR, "Node type must be 'binary expr'");
    check(node->binary_expr.lhs != NULL, "Binary expression LHS is required");
    
    // Retrieve the last variable reference in a chain to determine the type.
    qip_ast_node *lhs_target_node = node->binary_expr.lhs;
    if(lhs_target_node->type == QIP_AST_TYPE_VAR_REF) {
        rc = qip_ast_var_ref_get_last_member(lhs_target_node, &lhs_target_node);
        check(rc == 0, "Unable to retrieve LHS last member");
    }

    switch(node->binary_expr.operator) {
        // If this is an arithmetic operator then use the LHS type.
        case QIP_BINOP_PLUS:
        case QIP_BINOP_MINUS:
        case QIP_BINOP_MUL:
        case QIP_BINOP_DIV:
        {
            int rc = qip_ast_node_get_type(lhs_target_node, module, type_ref);
            check(rc == 0, "Unable to determine the binary expression type");
            break;
        }
        
        // Otherwise it's a boolean expression.
        default:
        {
            *type_ref = node->binary_expr.boolean_type_ref;
            break;
        }
    }
    
    return 0;

error:
    *type_ref = NULL;
    return -1;
}


//--------------------------------------
// Validation
//--------------------------------------

// Validates the AST node.
//
// node - The node to validate.
// module - The module that the node is a part of.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_validate(qip_ast_node *node, qip_module *module)
{
    int rc;
    bstring msg = NULL;
    check(node != NULL, "Node required");
    check(module != NULL, "Module required");
    
    // Retrieve the last variable reference in a chain to determine the type.
    qip_ast_node *lhs_target_node = node->binary_expr.lhs;
    if(lhs_target_node->type == QIP_AST_TYPE_VAR_REF) {
        rc = qip_ast_var_ref_get_last_member(lhs_target_node, &lhs_target_node);
        check(rc == 0, "Unable to retrieve LHS last member");
    }

    qip_ast_node *rhs_target_node = node->binary_expr.rhs;
    if(rhs_target_node->type == QIP_AST_TYPE_VAR_REF) {
        rc = qip_ast_var_ref_get_last_member(rhs_target_node, &rhs_target_node);
        check(rc == 0, "Unable to retrieve RHS last member");
    }
    
    // Determine types.
    bstring lhs_type, rhs_type;
    rc = qip_ast_node_get_type_name(lhs_target_node, module, &lhs_type);
    check(rc == 0, "Unable to determine the binary expression LHS type");
    rc = qip_ast_node_get_type_name(rhs_target_node, module, &rhs_type);
    check(rc == 0, "Unable to determine the binary expression RHS type");

    // Validate lhs=numeric, rhs=non-numeric.
    if((biseqcstr(lhs_type, "Int") || biseqcstr(lhs_type, "Float")) && (biseqcstr(rhs_type, "Boolean") || !qip_is_builtin_type_name(rhs_type))) {
        msg = bformat("Incompatible types (%s, %s)", bdata(lhs_type), bdata(rhs_type));
    }
    // Validate lhs=non-numeric, rhs=numeric.
    else if((biseqcstr(lhs_type, "Boolean") || !qip_is_builtin_type_name(lhs_type)) && (biseqcstr(rhs_type, "Int") || biseqcstr(rhs_type, "Float"))) {
        msg = bformat("Incompatible types (%s, %s)", bdata(lhs_type), bdata(rhs_type));
    }
    
    // If we have an error message then add it.
    if(msg != NULL) {
        rc = qip_module_add_error(module, node, msg);
        check(rc == 0, "Unable to add module error");
    }

    bdestroy(msg);
    return 0;

error:
    bdestroy(msg);
    return -1;
}


//--------------------------------------
// Find
//--------------------------------------

// Computes a list of type references used by a node.
//
// node      - The node.
// type_refs - A pointer to an array of type refs.
// count     - A pointer to where the number of type refs is stored.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_get_type_refs(qip_ast_node *node,
                                      qip_ast_node ***type_refs,
                                      uint32_t *count)
{
    int rc;
    check(node != NULL, "Node required");
    check(type_refs != NULL, "Type refs return pointer required");
    check(count != NULL, "Type ref count return pointer required");

    if(node->binary_expr.lhs) {
        rc = qip_ast_node_get_type_refs(node->binary_expr.lhs, type_refs, count);
        check(rc == 0, "Unable to add binary expr lhs");
    }

    if(node->binary_expr.rhs) {
        rc = qip_ast_node_get_type_refs(node->binary_expr.rhs, type_refs, count);
        check(rc == 0, "Unable to add binary expr rhs");
    }

    return 0;
    
error:
    qip_ast_node_type_refs_free(type_refs, count);
    return -1;
}

// Retrieves all variable reference of a given name within this node.
//
// node  - The node.
// name  - The variable name.
// array - The array to add the references to.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_get_var_refs(qip_ast_node *node, bstring name,
                                     qip_array *array)
{
    int rc;
    check(node != NULL, "Node required");
    check(name != NULL, "Variable name required");
    check(array != NULL, "Array required");

    if(node->binary_expr.lhs) {
        rc = qip_ast_node_get_var_refs(node->binary_expr.lhs, name, array);
        check(rc == 0, "Unable to add binary expr lhs");
    }

    if(node->binary_expr.rhs) {
        rc = qip_ast_node_get_var_refs(node->binary_expr.rhs, name, array);
        check(rc == 0, "Unable to add binary expr rhs");
    }

    return 0;
    
error:
    return -1;
}

// Retrieves all variable reference of a given type name within this node.
//
// node      - The node.
// module    - The module.
// type_name - The type name.
// array     - The array to add the references to.
//
// Returns 0 if successful, otherwise returns -1.
int qip_ast_binary_expr_get_var_refs_by_type(qip_ast_node *node, qip_module *module,
                                             bstring type_name, qip_array *array)
{
    int rc;
    check(node != NULL, "Node required");
    check(module != NULL, "Module required");
    check(type_name != NULL, "Type name required");
    check(array != NULL, "Array required");

    rc = qip_ast_node_get_var_refs_by_type(node->binary_expr.lhs, module, type_name, array);
    check(rc == 0, "Unable to add binary expr lhs by type");

    rc = qip_ast_node_get_var_refs_by_type(node->binary_expr.rhs, module, type_name, array);
    check(rc == 0, "Unable to add binary expr rhs by type");

    return 0;
    
error:
    return -1;
}


//--------------------------------------
// Debugging
//--------------------------------------

// Append the contents of the AST node to the string.
// 
// node - The node to dump.
// ret  - A pointer to the bstring to concatenate to.
//
// Return 0 if successful, otherwise returns -1.s
int qip_ast_binary_expr_dump(qip_ast_node *node, bstring ret)
{
    int rc;
    check(node != NULL, "Node required");
    check(ret != NULL, "String required");

    // Determine operator symbol.
    char *operator = "";
    switch(node->binary_expr.operator) {
        case QIP_BINOP_PLUS: operator = "+"; break;
        case QIP_BINOP_MINUS: operator = "-"; break;
        case QIP_BINOP_MUL: operator = "*"; break;
        case QIP_BINOP_DIV: operator = "/"; break;
        case QIP_BINOP_EQUALS: operator = "=="; break;
    }
    
    // Append dump.
    bstring str = bformat("<binary-expr operator='%s'>\n", operator);
    check_mem(str);
    check(bconcat(ret, str) == BSTR_OK, "Unable to append dump");

    // Recursively dump LHS & RHS.
    if(node->binary_expr.lhs != NULL) {
        rc = qip_ast_node_dump(node->binary_expr.lhs, ret);
        check(rc == 0, "Unable to dump LHS");
    }
    if(node->binary_expr.rhs != NULL) {
        rc = qip_ast_node_dump(node->binary_expr.rhs, ret);
        check(rc == 0, "Unable to dump RHS");
    }

    return 0;

error:
    if(str != NULL) bdestroy(str);
    return -1;
}
