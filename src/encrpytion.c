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
        sprintf(temp_destination,"%x",message[i]);
        //hex_array[i] = *temp_destination;
    }
    // for (int i = 0; i < 6; i++) {
    //     printf("%c \n",hex_array[i]);
    // }
    return hex_array;
}

int main(int argc, char *argv[]) {
    convert_to_hex("bilal");
    // printf("%c",foo[1]);
    //free(foo);
    return 0;
}