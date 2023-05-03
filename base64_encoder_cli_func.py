import os
import base64

# Define a function for Base64 encoding.
def base64_encode(text):
    base64_enc_text = base64.b64encode(text.encode('utf-8')).decode('utf-8')
    return base64_enc_text

# Clear the screen.
os.system('cls' if os.name == 'nt' else 'clear')

# Ask the user to input text to encode.
text = input(f"Input text to encode: ")

# Example usage of the Base64 encoding function.
base64_enc_text = base64_encode(text)
print(f"Base64 encoded text: {base64_enc_text}")