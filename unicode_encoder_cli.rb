# Clear the screen.
system('cls') || system('clear')

# Ask the user to input text to encode.
print "Input text to encode: "
text = gets.chomp

# Encode the inputted text using Unicode encoding.
unicode_enc_text = text.each_codepoint.map { |cp| "\\u#{cp.to_s(16).rjust(4, '0')}" }.join(' ')

# Print the Unicode encoded text.
puts "Unicode encoded text: #{unicode_enc_text}"