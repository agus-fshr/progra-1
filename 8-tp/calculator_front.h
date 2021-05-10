/*****************************************************************************
  @file     calculator_front.h
  @brief    Front-end of the calculator (.h)
  @author   Grupo 7
 ******************************************************************************/

#ifndef CALCULATOR_INPUT_H
#define CALCULATOR_INPUT_H


/******************************************
 * CONSTANT AND MACRO DEFS USING #DEFINE  *
 ******************************************/
#define OPERATOR_NOT_FOUND -1


/*****************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE *
 *****************************************/

/**
 * @brief Reads two operands and an operator from stdin.
 * @param op1 Pointer to the variable that stores the first operand
 * @param op2 Pointer to the variable that stores the second operand
 * @param operator Pointer to the variable that stores the operator char representation
 * @return 0 if there was an error, 1 otherwise.
 */
int parse_input(double *op1, double *op2, char *operator);


/**
 * @brief Prints tips for calculator use
 */
void print_calculator_tips(void);


/**
 * @brief Prints available operators
 * @param operators Array containing every operator-representing char
 * @param op_num Number of operators
 */
void print_operators(char operators[], int op_num);


/**
 * @brief Prints the expression to resolve and the result
 * @param op1 Left operand
 * @param op2 Right operand
 * @param operation Char representing operation
 * @param result The operation result
 */
void print_operation_result(double op1, double op2, char operation, double result);


/**
 * @brief Clears terminal in an OS-specific basis
 */
void clear_screen(void);


/**
 * @brief Flushes the stdin buffer. Takes characters from stdin until limit is found.
 * @param limit Character that indicates where to stop flushing
 */
void flush_stdin(char limit);

#endif