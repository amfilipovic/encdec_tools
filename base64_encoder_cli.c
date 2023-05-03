#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Base64 encoding table.
static const char base64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Define a function to Base64 encode a buffer of bytes.
void base64_encode(const unsigned char *src, size_t srclen, char *dst, size_t *dstlen) {
    size_t i, j;
    for (i = 0, j = 0; i < srclen; i += 3) {
        unsigned char a = i < srclen ? src[i] : 0;
        unsigned char b = i + 1 < srclen ? src[i + 1] : 0;
        unsigned char c = i + 2 < srclen ? src[i + 2] : 0;
        dst[j++] = base64_table[a >> 2];
        dst[j++] = base64_table[((a & 0x03) << 4) | ((b & 0xf0) >> 4)];
        dst[j++] = i + 1 < srclen ? base64_table[((b & 0x0f) << 2) | ((c & 0xc0) >> 6)] : '=';
        dst[j++] = i + 2 < srclen ? base64_table[c & 0x3f] : '=';
    }
    *dstlen = j;
    dst[j] = '\0';
}

int main() {
    // Clear the screen.
    system("cls");
    // Ask the user to input text to encode.
    char text[100];
    printf("Input text to encode: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = 0;
    // Encode the inputted text using Base64 encoding.
    size_t dstlen;
    char *base64_enc_text = malloc((strlen(text) * 4 / 3 + 4) * sizeof(char));
    base64_encode((const unsigned char *)text, strlen(text), base64_enc_text, &dstlen);
    // Print the Base64 encoded text.
    printf("Base64 encoded text: %s\n", base64_enc_text);
    // Free memory.
    free(base64_enc_text);
    return 0;
}