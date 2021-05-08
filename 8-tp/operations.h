#ifndef OPERATIONS_H
#define OPERATIONS_H

/**
 * @brief Adds two numbers together.
 *
 * @param a first number to be added.
 * @param second number to be added.
 * @return the sum of both numbers a and b.
 */
float suma(float a, float b);

/**
 * @brief Substracts two numbers.
 *
 * @param a number to substract from.
 * @param b number to substract.
 * @return result of a minus b.
*/
float resta(float a, float b);

/**
 * @brief Divides two numbers.
 *
 * @param a number to be divided.
 * @param b number to divide by.
 * @return the result of a divided by b.
*/
float division(float a, float b);

/**
 * @brief Calculates the product of two numbers.
 * 
 * @param a a factor.
 * @param b another factor.
 * @return the result of a times b.
 */
float mutiplicacion(float a, float b);
float potencia(float a, int b);
float sin(float a);
float factorial(int a);


#endif