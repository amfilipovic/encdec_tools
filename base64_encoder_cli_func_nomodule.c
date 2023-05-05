#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR_CMD "cls"
#else
#define CLEAR_CMD "clear"
#endif

// Define the Base64 encoding table.
const char* base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Define a function to Base64 encode a buffer of bytes.
char* base64_encode(const unsigned char* source, size_t srclen) {
    char* dst = (char*) malloc(((srclen + 2) / 3) * 4 + 1);
    size_t dstlen = 0;
    for (size_t i = 0; i < srclen; i += 3) {
        unsigned char a = source[i];
        unsigned char b = i + 1 < srclen ? source[i + 1] : 0;
        unsigned char c = i + 2 < srclen ? source[i + 2] : 0;
        dst[dstlen++] = base64_table[a >> 2];
        dst[dstlen++] = base64_table[((a & 0x03) << 4) | ((b & 0xf0) >> 4)];
        dst[dstlen++] = i + 1 < srclen ? base64_table[((b & 0x0f) << 2) | ((c & 0xc0) >> 6)] : '=';
        dst[dstlen++] = i + 2 < srclen ? base64_table[c & 0x3f] : '=';
    }
    dst[dstlen] = '\0';
    return dst;
}

int main() {
    // Clear the screen.
    system(CLEAR_CMD);
    // Ask the user to input text to encode.
    printf("Input text to encode: ");
    char text[100];
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    // Encode the inputted text using Base64 encoding.
    char* base64_enc_text = base64_encode((const unsigned char*)text, strlen(text));
    // Print the Base64 encoded text.
    printf("Base64 encoded text: %s\n", base64_enc_text);
    // Free memory.
    free(base64_enc_text);
    return 0;
}