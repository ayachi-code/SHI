#include <stdio.h>
#include <time.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"

int generate_prime_number() {
    srand(time(NULL));
    int prime_number1 = rand() % 1000;
    int prime_number2 = rand() % 1000;
    while (prime_number2 == prime_number1) {
        prime_number2 = rand() % 1000;
    }
    printf("%d %d \n",prime_number1,prime_number2);
}

int generate_publickey() { 
    return 1;
}

int main(int argc, char *argv[]) {
    generate_prime_number();
    return 0;
}