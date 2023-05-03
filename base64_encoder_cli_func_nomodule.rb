# Define the Base64 encoding table.
BASE_64_TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

# Define a function to Base64 encode a buffer of bytes.
def base64_encode(source)
    srclen = source.length
    dst = []
    (0...srclen).step(3) do |i|
    a = source[i].ord
    b = i + 1 < srclen ? source[i + 1].ord : 0
    c = i + 2 < srclen ? source[i + 2].ord : 0
    dst << BASE_64_TABLE[a >> 2]
    dst << BASE_64_TABLE[((a & 0x03) << 4) | ((b & 0xf0) >> 4)]
    dst << (i + 1 < srclen ? BASE_64_TABLE[((b & 0x0f) << 2) | ((c & 0xc0) >> 6)] : '=')
    dst << (i + 2 < srclen ? BASE_64_TABLE[c & 0x3f] : '=')
    end
    return dst.join('')
end

# Clear the screen.
system('cls') || system('clear')

# Ask the user to input text to encode.
print "Input text to encode: "
text = gets.chomp

# Encode the inputted text using Base64 encoding.
base64_enc_text = base64_encode(text.encode('utf-8').bytes)

# Print the Base64 encoded text.
puts "Base64 encoded text: #{base64_enc_text}"