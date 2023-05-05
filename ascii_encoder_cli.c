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
    char text[100];
    printf("Input text to encode: ");
    fgets(text, 100, stdin);
    // Remove the trailing newline character.
    text[strcspn(text, "\n")] = '\0';
    // Encode the inputted text using ASCII decimal encoding.
    char ascii_dec_enc_text[100];
    int i;
    int jdec = 0;
    for (i = 0; i < strlen(text); i++) {
        jdec += sprintf(&ascii_dec_enc_text[jdec], "%d ", text[i]);
    }
    ascii_dec_enc_text[jdec-1] = '\0';
    // Encode the inputted text using ASCII hexadecimal encoding.
    char ascii_hex_enc_text[100];
    for (i = 0; i < strlen(text); i++) {
    sprintf(&ascii_hex_enc_text[i*3], "%02X ", text[i]);
    }
    ascii_hex_enc_text[strlen(text)*3-1] = '\0';
    // Encode the inputted text using ASCII octal encoding.
    char ascii_oct_enc_text[100];
    int joct = 0;
    joct = 0;
    for (i = 0; i < strlen(text); i++) {
        sprintf(&ascii_oct_enc_text[joct], "%o ", (unsigned char) text[i]);
        joct += strlen(&ascii_oct_enc_text[joct]);
    }
    ascii_oct_enc_text[joct-1] = '\0';
    // Encode the inputted text using ASCII binary encoding.
    char ascii_bin_enc_text[100];
    for (i = 0; i < strlen(text); i++) {
        int num = text[i];
        for (int jbin = 7; jbin >= 0; jbin--) {
            int bit = (num >> jbin) & 1;
            ascii_bin_enc_text[i*9 + (7-jbin)] = bit ? '1' : '0';
        }
        ascii_bin_enc_text[i*9 + 8] = ' ';
    }
    ascii_bin_enc_text[strlen(text)*9-1] = '\0';
    // Print the ASCII decimal, hexadecimal, octal and binary encoded text.
    printf("ASCII decimal encoded text: %s\n", ascii_dec_enc_text);
    printf("ASCII hexadecimal encoded text: %s\n", ascii_hex_enc_text);
    printf("ASCII octal encoded text: %s\n", ascii_oct_enc_text);
    printf("ASCII binary encoded text: %s\n", ascii_bin_enc_text);
    return 0;
}