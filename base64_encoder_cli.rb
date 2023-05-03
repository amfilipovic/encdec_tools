require 'base64'

# Clear the screen.
system('cls') || system('clear')

# Ask the user to input text to encode.
print "Input text to encode: "
text = gets.chomp

# Encode the inputted text using Base64 encoding.
base64_enc_text = Base64.encode64(text.encode('utf-8')).chomp

# Print the Base64 encoded text.
puts "Base64 encoded text: #{base64_enc_text}"