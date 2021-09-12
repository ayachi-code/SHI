#include "../includes/usefull.h"

int string_length(char* message) {
    int message_length = 0;
    int characters_count = 0;
    while (message[characters_count] != '\0') { 
        characters_count++;
    }
    return characters_count;   
}