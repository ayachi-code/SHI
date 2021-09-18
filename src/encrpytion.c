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
    time_t t;
    srand((unsigned) time(&t));
    int random_number = 0;
    while (true) {
        random_number = 1000000000 + floor(rand() % 9999999999);
        if (is_prime(random_number)) {
            printf("%d is prime \n",random_number);
            break;
        }
    }
}

int* generate_publickey() { 
    return 1;
}

int main(int argc, char *argv[]) {
    return 0;
}