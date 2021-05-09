#ifndef OPERATIONS_H
#define OPERATIONS_H

#define PI 3.141592653589793238

/**
 * @brief Adds two numbers together.
 *
 * @param a first number to be added.
 * @param second number to be added.
 * @return the sum of both numbers a and b.
 */
double sum(double a, double b);

/**
 * @brief Substracts two numbers.
 *
 * @param a number to substract from.
 * @param b number to substract.
 * @return result of a minus b.
*/
double substraction(double a, double b);

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
double product(double a, double b);

/**
 * @brief Calculates a to the integer power b.
 * 
 * @param a base of the power.
 * @param b exponent of the power.
 * @return the result of a to the power b.
 */
double integer_power(double a, int b);

/**
 * @brief Calculates the sine of a.
 * 
 * @param a number to take the sine of.
 * @return sin(a).
 */
double sin(double a);

/**
 * @brief Calculates the cosine of a.
 * 
 * @param b number to take the sine of.
 * @return sin(a).
 */
double cos(double a);

/**
 * @brief Calculates a factorial.
 * 
 * @param a number to take the factorial of.
 * @return (a)!
 */
double factorial(unsigned int b);


#endif