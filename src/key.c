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
    bignum_from_int(&primenumber1, 11);
    bignum_from_int(&primenumber2, 23);
    char x[9000];
    bignum_mul(&primenumber1, &primenumber2, &primenumber_multiplication);
    bignum_assign(&primenumber1_dec,&primenumber1);
    bignum_assign(&primenumber2_dec,&primenumber2);
    bignum_dec(&primenumber1_dec);
    bignum_dec(&primenumber2_dec);
    bignum_mul(&primenumber1_dec, &primenumber2_dec, &totient);
    bignum_to_string(&totient, x, sizeof(x));
    char* buf =  (char*) malloc(20*sizeof(char));
    char buf2[10240];
    long e = public_ekey(totient,primenumber_multiplication);
    sprintf(buf,"%lx",e);
    bignum_to_string(&totient, buf2, sizeof(buf2));
    char* public_keypair = (char*) malloc(2 * sizeof(char));
    int bilal = 12;
    insert_buffers_in_array(&bilal);
    printf("%d \n",bilal);
    // public_keypair[0] = buf2[0];
    // public_keypair[1] = buf2[1];
    // public_keypair[1] = *buf2; 
    // printf("%s \n", buf);
    // printf("%c %c \n", public_keypair[0],public_keypair[1]);
    return public_keypair;
}
//The raven
char* generate_privatekey(char public_ekey, char totient) {
    struct bn e;
    struct bn totients;
    struct bn e_d_mult;
    char public_ekey_hex[9000];
    char buf[1024];
    char buf2[1024];
    sprintf(buf, "%c", public_ekey);
    sprintf(buf2, "%c", totient);
    bignum_from_string(&e, buf, 8); 
    bignum_from_string(&totients, buf2, 8); 
    struct bn d;
    struct bn d_e;
    struct bn mod_val;
    struct bn mod1;
    bignum_from_int(&mod1,1);
    bignum_from_int(&d, 2);
    while (true) {
        bignum_mul(&d, &e, &d_e);
        bignum_mod(&d_e, &totients, &mod_val);
        if (bignum_cmp(&mod_val, &mod1) == EQUAL) {
            bignum_to_string(&d, public_ekey_hex, sizeof(public_ekey_hex));
            printf("DIT IS DE PRIVATE KEY  ");
            printf("%s \n ",public_ekey_hex);
            break;
        }
        bignum_inc(&d);
    }
}

int main(int argc, char *argv[]) {
    time_t t; 
    srand((unsigned) time(&t));
    char* public_pair = generate_publickey();
    // generate_privatekey(public_pair[0],public_pair[1]);
    return 0;
} 