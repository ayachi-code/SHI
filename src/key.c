#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/key.h"
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
    while (true) {
        random_number = 1000000000 + floor(rand() % 9999999999);
        if (is_prime(random_number)) {
            return random_number;
        }
    }
}

char* generate_publickey() { 
    struct bn primenumber1;
    struct bn primenumber2;
    struct bn primenumber_multiplication;
    struct bn totient;
    struct bn primenumber1_dec;
    struct bn primenumber2_dec;
    bignum_from_int(&primenumber1, 2);
    bignum_from_int(&primenumber2, 7);
    bignum_mul(&primenumber1, &primenumber2, &primenumber_multiplication);
    bignum_assign(&primenumber1_dec,&primenumber1);
    bignum_assign(&primenumber2_dec,&primenumber2);
    bignum_dec(&primenumber1_dec);
    bignum_dec(&primenumber2_dec);
    bignum_mul(&primenumber1_dec, &primenumber2_dec, &totient);
    long x = public_ekey(totient,primenumber_multiplication);
    char* buf =  (char*) malloc(20*sizeof(char));
    char buf2[512];
    sprintf(buf,"%lx",x);
    bignum_to_string(&primenumber_multiplication, buf2, sizeof(buf2));
    char* public_keypair = malloc(2 * sizeof(char));
    public_keypair[0] = *buf;
    public_keypair[1] = *buf2; 
    return public_keypair;
}
//The raven
char* generate_privatekey(char public_ekey, char product) {
    //ed = 1 mod(product)
    struct bn e;
    struct bn products;
    struct bn e_d_mult;
    char public_ekey_hex[9000];
    char buf[1024];
    char buf2[1024];
    sprintf(buf, "%c", public_ekey);
    sprintf(buf2, "%c", product);
    bignum_from_string(&e, buf, 8); 
    bignum_from_string(&products, buf2, 8); 
    bignum_mul(&e,&products, &e_d_mult);
    bignum_to_string(&e_d_mult, public_ekey_hex, sizeof(public_ekey_hex));
    printf("%s ",public_ekey_hex);
}

int main(int argc, char *argv[]) {
    time_t t; 
    srand((unsigned) time(&t));
    char* public_pair = generate_publickey();
    // printf("%c \n",public_pair[1]);
    generate_privatekey(public_pair[0],public_pair[1]);
    return 0;
} 