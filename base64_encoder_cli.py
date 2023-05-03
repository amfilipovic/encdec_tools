import os
import base64

# Clear the screen.
os.system('cls' if os.name == 'nt' else 'clear')

# Ask the user to input text to encode.
text = input(f"Input text to encode: ")

# Encode the inputted text using Base64 encoding.
base64_enc_text = base64.b64encode(text.encode('utf-8')).decode('utf-8')

# Print the Base64 encoded text.
print(f"Base64 encoded text: {base64_enc_text}")