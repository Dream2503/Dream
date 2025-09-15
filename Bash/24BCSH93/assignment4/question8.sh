# Q8. Write a shell script to count number of characters, words, white spaces and special symbols in a file.

#!/bin/bash
echo -n "Enter the file name: "
read file

chars=$(grep -o . "$file" | wc -l)
words=$(grep -o "[a-zA-Z0-9]\+" "$file" | wc -l)
spaces=$(grep -o " " "$file" | wc -l)
specials=$(grep -o "[^a-zA-Z0-9 ]" "$file" | wc -l)

echo "File: $file"
echo "Characters: $chars"
echo "Words: $words"
echo "Spaces: $spaces"
echo "Special symbols: $specials"
