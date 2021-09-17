#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"
#include <math.h>
#include <stdint.h>

//cpp com
bool is_prime(int number) {
    if (number % 2 == 0) {
        printf("Geen prime \n");
        return false;
    }
    int k = 1;
    double n = number-1;
    int a = 2;
    double m = n;
    while (true) {
        m = n/pow(2,k);
        if (fmod(m,1)==0) {
            k++; //2
        } else {
            k--;
            m *= 2;
            n = m;
            break;
        }
    }
    uint64_t b0 = modulo(2,n,number);
    if (b0 == modulo(1,1,number) || b0 == number-1) {
        printf("Prime \n");
        return true;
    }   
    uint64_t b1 = 0;
    for (int failed_cases = 0; failed_cases < 12; failed_cases++) {
         b1 = modulo(b0,2,number);
        if (b1 == modulo(1,1,number)) {
            printf("geen prime \n");
        } else if (b1 == number-1) {
            printf("Prime \n");
        } else {
            failed_cases++;
            b0 = b1;
        }
    }
    if (failed_cases >= 12) {
        printf("geen prime \n");
    }
}
int generate_publickey() { 
    return 1;
}

int main(int argc, char *argv[]) {
    is_prime(123);
    return 0;
}