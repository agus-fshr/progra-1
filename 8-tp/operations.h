#ifndef OPERATIONS_H
#define OPERATIONS_H

/**
 * @brief Adds two numbers together.
 *
 * @param a first number to be added.
 * @param second number to be added.
 * @return the sum of both numbers a and b.
 */
double suma(double a, double b);

/**
 * @brief Substracts two numbers.
 *
 * @param a number to substract from.
 * @param b number to substract.
 * @return result of a minus b.
*/
double resta(double a, double b);

/**
 * @brief Divides two numbers.
 *
 * @param a number to be divided.
 * @param b number to divide by.
 * @return the result of a divided by b.
*/
double division(double a, double b);

/**
 * @brief Calculates the product of two numbers.
 * 
 * @param a a factor.
 * @param b another factor.
 * @return the result of a times b.
 */
double multiplicacion(double a, double b);

/**
 * @brief Calculates a to the power b.
 * 
 * @param a base of the power.
 * @param b exponent of the power.
 * @return the result of a to the power b.
 */
double potencia(double a, double b);

/**
 * @brief Calculates sine of a.
 * 
 * @param a number to take the sine of.
 * @param b nothing
 * @return sin(a).
 */
double sen(double a, double b);

/**
 * @brief Calculates a factorial.
 * 
 * @param a number to take the factorial of.
 * @param b nothing
 * @return a!
 */
double factorial(double a, double b);


#endif