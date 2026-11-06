// parse/parse_args.c

// Go through the arguments. Build stack a. The first number is the top.
// On any error: free what you made, print Error to stderr, stop.
// Test: 0 one 2 3, 3 2 3, 99999999999, -, +5, -2147483648, 2147483647, no arguments. Compare with the subject examples. valgrind after errors too.