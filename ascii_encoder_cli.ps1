# Clear the screen.
Clear-Host

# Ask the user to input text to encode.
$text = Read-Host "Input text to encode"

# Encode the inputted text using ASCII decimal encoding.
$ascii_dec_enc_text = [String]::Join(' ', ([Char[]]$text.ToCharArray() | ForEach-Object { [Int][Char]$_ }))

# Encode the inputted text using ASCII hexadecimal encoding.
$ascii_hex_enc_text = [String]::Join(' ', ([Char[]]$text.ToCharArray() | ForEach-Object { [Convert]::ToString([Int][Char]$_, 16).ToUpper() }))

# Encode the inputted text using ASCII octal encoding.
$ascii_oct_enc_text = [String]::Join(' ', ([Char[]]$text.ToCharArray() | ForEach-Object { [Convert]::ToString([Int][Char]$_, 8) }))

# Encode the inputted text using ASCII binary encoding.
$ascii_bin_enc_text = [String]::Join(' ', ([Char[]]$text.ToCharArray() | ForEach-Object { [Convert]::ToString([Int][Char]$_, 2).PadLeft(8, '0') }))

# Print the ASCII decimal, hexadecimal, octal and binary encoded text.
Write-Host "ASCII decimal encoded text: $ascii_dec_enc_text"
Write-Host "ASCII hexadecimal encoded text: $ascii_hex_enc_text"
Write-Host "ASCII octal encoded text: $ascii_oct_enc_text"
Write-Host "ASCII binary encoded text: $ascii_bin_enc_text"

#$ascii_dec_enc_text = ($text.ToCharArray() | ForEach-Object { [int][char]$_ }) -join ' '
#$ascii_hex_enc_text = ($text.ToCharArray() | ForEach-Object { "{0:X}" -f [int][char]$_ }) -join ' '
#$ascii_oct_enc_text = ($text.ToCharArray() | ForEach-Object { "{0:03}" -f [int][char]$_ }) -join ' '
#$ascii_bin_enc_text = ($text.ToCharArray() | ForEach-Object { "{0:B8}" -f [convert]::ToString([int][char]$_, 2) }) -join ' '