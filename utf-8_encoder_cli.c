#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_CMD "cls"
#else
#define CLEAR_CMD "clear"
#endif

int main() {
    // Clear the screen.
    system(CLEAR_CMD);
    // Ask the user to input text to encode.
    printf("Input text to encode: ");
    char text[100];
    fgets(text, sizeof(text), stdin);
    // Remove the trailing newline character.
    text[strcspn(text, "\n")] = '\0';
    // Encode the inputted text using UTF-8 code page encoding.
    char text2encode_utf8_cp[1000];
    int index = 0;
    for (int i = 0; i < strlen(text); i++) {
        index += sprintf(&text2encode_utf8_cp[index], "U+%04X ", (unsigned int)text[i]);
    }
    // Encode the inputted text using UTF-8 hexadecimal encoding.
    char text2encode_utf8_hex[1000];
    index = 0;
    for (int i = 0; i < strlen(text); i++) {
        index += sprintf(&text2encode_utf8_hex[index], "%02X ", (unsigned int)text[i]);
    }
    // Print the UTF-8 code page and hexadecimal encoded text.
    printf("UTF-8 code page encoded text: %s\n", text2encode_utf8_cp);
    printf("UTF-8 hexadecimal encoded text: %s\n", text2encode_utf8_hex);
    return 0;
}