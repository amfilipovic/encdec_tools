import os

# Clear the screen.
os.system('cls' if os.name == 'nt' else 'clear')

# Ask the user to input text to encode.
text = input("Input text to encode: ")

# Encode the inputted text using UTF-8 code page encoding.
text2encode_utf8_cp = ' '.join([f'U+{ord(c):04X}' for c in text])

# Encode the inputted text using UTF-8 hexadecimal encoding.
text2encode_utf8_hex = ' '.join([f'{ord(c):02X}' for c in text])

# Print the UTF-8 code page encoded text.
print(f"UTF-8 code page encoded text: {text2encode_utf8_cp}")

# Print the UTF-8 hexadecimal encoded text.
print(f"UTF-8 hexadecimal encoded text: {text2encode_utf8_hex}")