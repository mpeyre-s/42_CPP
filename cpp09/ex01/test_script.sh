#!/bin/bash

echo -e "Test with input: '8 9 * 9 - 9 - 9 - 4 - 1 +' (must be 42)"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "-----------------------"

echo -e "Test with input: '7 7 * 7 -' (must be 42)"
./RPN "7 7 * 7 -"
echo "-----------------------"

echo -e "Test with input: '1 2 * 2 / 2 * 2 4 - +' (must be 0)"
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "-----------------------"

echo -e "Test with input: '(1 + 1)' (must be Error)"
./RPN "(1 + 1)"
echo "-----------------------"
