#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "../includes/libs/bn.h"

//cpp com
bool is_prime(int number) {
    if (number % 2 == 0) {
        return false;
    }
    int k = 1;
    double n = number-1;
    int a = 2;
    double m = n;
    while (true) {
        m = n/pow(2,k);
        if (fmod(m,1)==0) {
            k++;
        } else {
            k--;
            m *= 2;
            n = m;
            break;
        }
    }
    uint64_t b0 = modulo(2,n,number);
    if (b0 == modulo(1,1,number) || b0 == number-1) {
        return true;
    }   
    uint64_t b1 = 0;
    for (int failed_cases = 0; failed_cases < 12; failed_cases++) {
         b1 = modulo(b0,2,number);
        if (b1 == modulo(1,1,number)) {
            return false;
        } else if (b1 == number-1) {
            return true;
        } else {
            failed_cases++;
            b0 = b1;
        }
    }
    return false;
}

int generate_prime() {
    int random_number = 0;
    // struct bn random_number;
    // bignum_init(&primenumber);
    while (true) {
        random_number = 1000000000 + floor(rand() % 9999999999);
        if (is_prime(random_number)) {
            return random_number;
        }
    }
}

int* generate_publickey() { 
    struct bn primenumber1;
    struct bn primenumber2;
    struct bn primenumber_multiplication;
    struct bn totient;
    struct bn primenumber1_dec;
    struct bn primenumber2_dec;
    bignum_from_int(&primenumber1, generate_prime());
    bignum_from_int(&primenumber2, generate_prime());
    bignum_mul(&primenumber1, &primenumber2, &primenumber_multiplication);
    bignum_assign(&primenumber1_dec,&primenumber1);
    bignum_assign(&primenumber2_dec,&primenumber2);
    bignum_dec(&primenumber1_dec);
    bignum_dec(&primenumber2_dec);
    bignum_mul(&primenumber1_dec, &primenumber2_dec, &totient);
    char str[256];
    bignum_to_string(&totient, str, sizeof(str));
    printf("%s \n",str);
    return 1;
}

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));
    generate_publickey();
    return 0;
}