#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"
#include <math.h>
//cpp com
bool is_prime(int number) {
    int k = 1;
    double n = 53-1;
    while (true) {
        n /= pow(2,k);
        if (fmod(n,1)==0) {
            k++;
        } else {
            n *= pow(2,k);
            break;
        }
    }
    printf("%f \n",n);
}

int generate_publickey() { 
    return 1;
}

int main(int argc, char *argv[]) {
    is_prime(21);
    return 0;
}