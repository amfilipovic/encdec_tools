import os

# Clear the screen.
os.system('cls' if os.name == 'nt' else 'clear')

# Ask the user to input text to encode.
text = input("Input text to encode: ")

# Encode the inputted text using ASCII decimal encoding.
ascii_dec_enc_text = ' '.join(str(ord(c)) for c in text)

# Encode the inputted text using ASCII hexadecimal encoding.
ascii_hex_enc_text = ' '.join(hex(ord(c))[2:] for c in text).upper()

# Encode the inputted text using ASCII octal encoding.
ascii_oct_enc_text = ' '.join(oct(ord(c))[2:] for c in text)

# Encode the inputted text using ASCII binary encoding.
ascii_bin_enc_text = ' '.join(format(ord(c), '08b') for c in text)

# Print the ASCII decimal, hexadecimal, octal and binary encoded text.
print(f"ASCII decimal encoded text: {ascii_dec_enc_text}")
print(f"ASCII hexadecimal encoded text: {ascii_hex_enc_text}")
print(f"ASCII octal encoded text: {ascii_oct_enc_text}")
print(f"ASCII binary encoded text: {ascii_bin_enc_text}")