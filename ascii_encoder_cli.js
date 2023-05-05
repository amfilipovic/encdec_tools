// Clear the screen.
console.clear();

// Ask the user to input text to encode.
const text = prompt("Input text to encode:");

// Encode the inputted text using ASCII decimal encoding.
const asciiDecEncText = text.split('').map(c => c.charCodeAt(0)).join(' ');

// Encode the inputted text using ASCII hexadecimal encoding.
const asciiHexEncText = text.split('').map(c => c.charCodeAt(0).toString(16).toUpperCase()).join(' ');

// Encode the inputted text using ASCII octal encoding.
const asciiOctEncText = text.split('').map(c => c.charCodeAt(0).toString(8)).join(' ');

// Encode the inputted text using ASCII binary encoding.
const asciiBinEncText = text.split('').map(c => c.charCodeAt(0).toString(2).padStart(8, "0")).join(' ');

// Print the ASCII decimal, hexadecimal, octal and binary encoded text.
console.log(`ASCII decimal encoded text: ${asciiDecEncText}`);
console.log(`ASCII hexadecimal encoded text: ${asciiHexEncText}`);
console.log(`ASCII octal encoded text: ${asciiOctEncText}`);
console.log(`ASCII binary encoded text: ${asciiBinEncText}`);