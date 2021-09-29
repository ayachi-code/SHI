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
    long temp = 0;
    long extra = 0;
    while (true) {
        temp = number1 / number2;
        extra = number1 - (number2*temp);
        if (extra == 0) {
            return number2;
        }
        number1 = number2;
        number2 = extra;
    }
}

long public_ekey(struct bn totien, struct bn N) {
    char buf[256]; //malloc
    char buf2[512]; //malloc
    bignum_to_string(&totien, buf, sizeof(buf));
    bignum_to_string(&N, buf2, sizeof(buf2));
    long totient_digits = strtol(buf, NULL, 16);
    long N_digits = strtol(buf2, NULL, 16);
    long e = 0;
    while (true) {
        e = rand() % (totient_digits-2) + 2;
        if (gcd(totient_digits,e) == 1 && gcd(N_digits,e) == 1) {
            return e;
        }
    }
}

int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int _x, _y;
    int gcd = extended_gcd(b % a, a, &_x, &_y);
    *x = _y - (b/a) * _x;
    *y = _x;
    return gcd;
}