import os

# Clear the screen.
os.system('cls' if os.name == 'nt' else 'clear')

# Ask the user to input text to encode.
text = input("Input text to encode: ")

# Encode the inputted text using Unicode encoding.
unicode_enc_text = ' '.join(['\\u{:04x}'.format(ord(c)) for c in text])

# Remove the BOM (Byte Order Mark) and null characters at the beginning of the byte sequence from output.
unicode_enc_text_clean = unicode_enc_text.replace('\\ufeff', '').replace('\\u0000', '')

# Print the Unicode encoded text cleaned from BOM and null characters.
print(f"Unicode encoded text: {unicode_enc_text_clean}")