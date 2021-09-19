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
    bignum_from_int(&primenumber1, generate_prime());
    bignum_from_int(&primenumber2, generate_prime())''
    
    return 1;
}

int main(int argc, char *argv[]) {
    time_t t;
    srand((unsigned) time(&t));
    generate_publickey();

    struct bn x;
    struct bn y;
    struct bn z;
    // int a = generate_prime();
    // int b = generate_prime();
    // bignum_from_int(&x, a);
    // bignum_from_int(&y, b);
    // bignum_mul(&x,&y,&z);
    // char buf3[256];
    // bignum_to_string(&z, buf3, sizeof(buf3));
    // printf("%d x %d = %s \n",a,b,buf3);

    return 0;
}