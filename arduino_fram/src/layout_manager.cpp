#include <stdio.h>
#include <string.h>
#include "layout_manager.hpp"

char *us_to_fr(char* str) {
    for (int index = 0; index < strlen(str); index++) {
        for (int letter = 0; letter < 2; letter++) { 
            if (str[index] == layout_k[letter].us[0]) {  
                str[index] = layout_k[letter].fr[0]; 
            }
        }
    }
    return str;
}

char *fr_to_us(char* str) {
    for (int index = 0; index < strlen(str); index++) {
        for (int letter = 0; letter < 2; letter++) { 
            if (str[index] == layout_k[letter].fr[0]) {  
                str[index] = layout_k[letter].us[0]; 
            }
        }
    }
    return str; 
}

// int main() {
//     char *message = strdup("fr: azertyuiop\nus: qwertyuiop\n");

//     printf("raw:\n%s\n", message);
//     message = us_to_fr(message);
//     printf("us->fr:\n%s\n", message);

//     message = fr_to_us(message);
//     printf("fr->us:\n%s\n", message);

//     return 0;
// }