#include <stdio.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"

/**
 * This encryption is made by Bilal
**/

char* convert_to_hex(char* message) {
    int x = string_length(message);
    printf("%d",x);
    //char* hex_array = (char*) malloc(sizeof(char*) * 5);
    return message;
}

int main(int argc, char *argv[]) {
    convert_to_hex(argv[1]);
    return 0;
}