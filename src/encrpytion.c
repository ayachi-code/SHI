#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"
#include <math.h>


//ALS 
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
    //double x = 0;
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
    //printf("%f %d \n",n,k);
    int b0 = fmod(pow(2,n),number);
    printf("%d b\n",b0);
    if (b0 == fmod(1,number) || b0 == number-1) {
        printf("Prime \n");
        return true;
    }
}

int generate_publickey() { 
    return 1;
}

int main(int argc, char *argv[]) {
    is_prime(87);
    return 0;
}