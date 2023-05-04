# Clear the screen.
system('cls') || system('clear')

# Ask the user to input text to encode.
print "Input text to encode: "
text = gets.chomp

# Encode the inputted text using ASCII decimal encoding.
ascii_dec_enc_text = text.chars.map(&:ord).join(' ')

# Encode the inputted text using ASCII hexadecimal encoding.
ascii_hex_enc_text = text.chars.map { |c| c.ord.to_s(16) }.join(' ').upcase

# Encode the inputted text using ASCII octal encoding.
ascii_oct_enc_text = text.chars.map { |c| c.ord.to_s(8) }.join(' ')

# Encode the inputted text using ASCII binary encoding.
ascii_bin_enc_text = text.chars.map { |c| c.ord.to_s(2).rjust(8, "0") }.join(' ')

# Print the ASCII decimal, hexadecimal, octal and binary encoded text.
puts "ASCII decimal encoded text: #{ascii_dec_enc_text}"
puts "ASCII hexadecimal encoded text: #{ascii_hex_enc_text}"
puts "ASCII octal encoded text: #{ascii_oct_enc_text}"
puts "ASCII binary encoded text: #{ascii_bin_enc_text}"