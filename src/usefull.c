#include "../includes/usefull.h"

int string_length(char* message) {
    int message_length = 0;
    int characters_count = 0;
    while (message[characters_count] != '\0') { 
        characters_count++;
    }
    return characters_count;   
}

long long modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

int gcd(long number1, long number2) {
    printf("%ld \n", number1);
    printf("%ld \n", number2);
    return 0;
}

struct bn public_ekey(struct bn totien, struct bn N) {
    char buf[256];
    char buf2[512];
    bignum_to_string(&totien, buf, sizeof(buf));
    bignum_to_string(&N, buf2, sizeof(buf2));
    long totient_digits = strtol(buf, NULL, 16);
    long N_digits = strtol(buf2, NULL, 16);
    long e = 0;
    gcd(2,3);
    // while (true) {
    //     e = rand() % (totient_digits-2) + 2;
    //     printf("%ld \n",e);
    //     printf("%ld \n",totient_digits);
    //     // if (x % totient_digits != 0) {
    //     //     printf("FOO \n");
    //     //     break;
    //     // }
    //     break;
    // }
}