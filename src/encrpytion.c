#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"
#include <math.h>
//cpp com
bool is_prime(int number) {
    int k = 1;
    double n = number-1;
    int a = 2;
    double m = n;
    while (true) {
        m = n/pow(2,k);
        //printf("%f \n",m);
        if (fmod(m,1)==0) {
            k++;
        } else {
            m *= 2;
            break;
        }
    }
    //printf("%f %d \n",n,k);
    // int b0 = fmod(pow(2,n),number);
    // if (b0 == fmod(1,number) || b0 == number-1) {
    //     printf("Prime \n");
    // }
    // double b1 = 0;
    // while (true) {
    //     b1 = fmod(pow(b0,2),number);
    //     printf("%f \n", b1);
    //     if (b1 == fmod(1,number)) {
    //         printf("geen prime \n");
    //         break;
    //     } else if (b1 == number-1) {
    //         printf("PRIME \n");
    //         break;
    //     } else {
    //         printf("volgende itteratie %f \n",b1);
    //         break;
    //     }
    // }
    // int b1 = 0;
    // while (true) {
    //     b1 = fmod(pow(),number);
    // }
}

int generate_publickey() { 
    return 1;
}

int main(int argc, char *argv[]) {
    is_prime(53);
    return 0;
}