#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/key.h"
#include "../includes/usefull.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "../includes/libs/bn.h"

//TODO maak multi dimendie array om de public pair op te slaan
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
            printf("%d \n", random_number);
            return random_number;
        }
    }
}

struct public_key_pair generate_publickey() { 
    struct bn primenumber1;
    struct bn primenumber2;
    struct bn primenumber_multiplication;
    struct bn totient;
    struct bn primenumber1_dec;
    struct bn primenumber2_dec;
    bignum_from_int(&primenumber1, 5);
    bignum_from_int(&primenumber2,11);
    char x[9000];
    char vb[9000];
    bignum_mul(&primenumber1, &primenumber2, &primenumber_multiplication);
    bignum_to_string(&primenumber_multiplication, vb, sizeof(vb));
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
    struct public_key_pair pair;
    pair.e_value = buf;
    pair.totient = buf2;
    pair.product = vb;
    return pair;
}

char* generate_privatekey(char* public_ekey, char* totient) {
    struct bn e;
    struct bn totients;
    struct bn e_d_mult;
    static char public_ekey_hex[9000];
    char buf[1024];
    char buf2[1024];
    char buf3[1024];
    sprintf(buf, "%s", public_ekey);
    sprintf(buf2, "%s", totient);
    int x, y;
    long public_ekey_d = strtol(public_ekey, NULL, 16);
    long totient_d = strtol(totient, NULL, 16);
    printf("%ld %ld \n",public_ekey_d, totient_d);
    extended_gcd(public_ekey_d, totient_d, &x, &y);
    printf("BI %d %d \n",x,y);
    if (x < 0) {
        int pd = totient_d + x;
        printf("-PK is %d \n",pd);
    } else {
        printf("+PK is %d \n",x);
    }
    // if (x > y) {
    //     return x;
    // } else if (y > x) {
    //     return y;
    // }
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
            return public_ekey_hex;
        }
        bignum_inc(&d);
    }
}

int main(int argc, char *argv[]) {
    time_t t; 
    srand((unsigned) time(&t));
    struct public_key_pair public_pair = generate_publickey();
    // int x = generate_privatekey(public_pair.e_value,public_pair.totient);
    char* x = generate_privatekey(public_pair.e_value,public_pair.totient);
    // printf("%d \n",x);
    long x_o = strtol(x, NULL, 16);
    long y_o = strtol(public_pair.product, NULL, 16);
    long e_o = strtol(public_pair.e_value, NULL, 16);
    printf("Public key (%ld,%ld) \n",e_o,y_o);
    printf("Private key (%ld,%ld)\n",x_o,y_o);
    // int a = 21;
    // int b = 11;
    // int x, y;
    // printf("The GCD is %d\n", extended_gcd(a, b, &x, &y));
    // printf("x = %d, y = %d", x, y);
    return 0;
}
//CRACKER
//(530, 713) private 
//BILAL
//C = 3

