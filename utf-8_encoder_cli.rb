# Clear the screen.
system('cls') || system('clear')

# Ask the user to input text to encode
print "Input text to encode: "
text = gets.chomp

# Encode the inputted text using UTF-8 code page encoding.
text2encode_utf8_cp = text.chars.map { |c| "U+#{c.ord.to_s(16).upcase.rjust(4, '0')}" }.join(' ')

# Encode the inputted text using UTF-8 hexadecimal encoding.
text2encode_utf8_hex = text.bytes.map { |b| format('%02X', b) }.join(' ')

# Print the UTF-8 code page encoded text.
puts "UTF-8 code page encoded text: #{text2encode_utf8_cp}"

# Print the UTF-8 hexadecimal encoded text.
puts "UTF-8 hexadecimal encoded text: #{text2encode_utf8_hex}"