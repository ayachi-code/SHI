#include <stdio.h>
#include "../includes/encryption.h"
#include "../includes/usefull.h"

/**
 * This encryption is made by Bilal
**/

char* convert_to_hex(char* message) {
    int str_length = string_length(message);
    char* hex_array = (char*) malloc(sizeof(char*) * str_length);
    char temp_destination[3];
    for (int i = 0; i < str_length; i++) {
        sprintf(temp_destination,"%02x",message[i]);
        hex_array[i] = (int)strtol(temp_destination, NULL, 16);
    }
    return hex_array;
}

int main(int argc, char *argv[]) {
    char* hex_array = convert_to_hex("bilal");
    free(hex_array);
    return 0;
}