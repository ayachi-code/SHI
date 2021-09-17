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