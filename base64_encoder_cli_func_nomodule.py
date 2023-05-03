import os

# Define the Base64 encoding table.
base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

# Define a function to Base64 encode a buffer of bytes.
def base64_encode(source):
    srclen = len(source)
    dst = bytearray()
    for i in range(0, srclen, 3):
        a = source[i]
        b = source[i + 1] if i + 1 < srclen else 0
        c = source[i + 2] if i + 2 < srclen else 0
        dst.append(ord(base64_table[a >> 2]))
        dst.append(ord(base64_table[((a & 0x03) << 4) | ((b & 0xf0) >> 4)]))
        dst.append(ord(base64_table[((b & 0x0f) << 2) | ((c & 0xc0) >> 6)]) if i + 1 < srclen else ord('='))
        dst.append(ord(base64_table[c & 0x3f]) if i + 2 < srclen else ord('='))
    return dst.decode('utf-8')

# Clear the screen.
os.system('cls' if os.name == 'nt' else 'clear')

if __name__ == '__main__':
    # Ask the user to input text to encode.
    text = input("Input text to encode: ")
    # Encode the inputted text using Base64 encoding.
    base64_enc_text = base64_encode(text.encode('utf-8'))
    # Print the Base64 encoded text.
    print("Base64 encoded text:", base64_enc_text)