#include "libs/bn.h"

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
struct bn public_ekey(struct bn totien, struct bn N);