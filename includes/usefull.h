#include "libs/bn.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * @returns returns the length of the message
 **/ 
int string_length(char* message);


/**
 * @returns returns the exponential modulu of the number
 **/  
long long modulo(long long base, long long exponent, long long mod);

/**
 * @returns public key decription pair (x,y) returns x 
 * @param totien the totient value of the 2 prime numbers
 * @param N the product of the two primes
 **/
long public_ekey(struct bn totien, struct bn N);

/**
 * @return returns the greatest common factorof the 2 numbers
 * @param number1 a postive integer
 * @param number2 a postive integer
 * @note the gcd is calculated with the Euclid's algorithm.
 **/  
int gcd(long number1, long number2);


/**
 *@param array the array where u want the string to be written
 *@param buffer1 buffer 1 
 *@param buffer2 buffer 2

*/
void insert_buffers_in_array(char *array, char*buffer1, char*buffer2);

/**
 * 
 **/ 
int extended_gcd(int a, int b, int *x, int *y);
