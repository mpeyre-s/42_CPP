#!/bin/bash

test_cases=(
	"a"            # A single character
	"A"            # Another character
	"z"            # Another character
	"Z"            # Another character
	" "            # A space
	"!"            # A special character
	"1"            # A digit
	"\0"           # Null character
	"42.0"         # A float
	"nan"          # Pseudo-literal (nan)
	"+inf"         # Pseudo-literal (+inf)
	"-inf"         # Pseudo-literal (-inf)
	"nanf"         # Pseudo-literal (nanf)
	"+inff"        # Pseudo-literal (+inff)
	"-inff"        # Pseudo-literal (-inff)
	"0"            # Subject test
	"42.0f"        # Subject test
	"abc"          # Invalid string
	""             # Empty string
	"123abc"       # String with number and letters
	"4.2ff"        # Invalid float
)

run_test() {
	echo -e "Test with input: '$1'"
	./convert "$1"
	echo "---------------------------------------------------"
}

for test_case in "${test_cases[@]}"; do
	run_test "$test_case"
done
