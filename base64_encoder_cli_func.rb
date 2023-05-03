require 'base64'

# Clear the screen.
system('clear') || system('cls')

# Define a function for Base64 encoding.
def base64_encode(text)
    Base64.strict_encode64(text)
end

# Ask the user to input text to encode.
print "Input text to encode: "
text = gets.chomp

# Example usage of the Base64 encoding function.
base64_enc_text = base64_encode(text)
puts "Base64 encoded text: #{base64_enc_text}"