# Palindrome Integer

## Description
This project involves writing a function that checks whether a given unsigned integer is a palindrome. A palindrome is a number that remains the same when its digits are reversed.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- Compilation on Ubuntu 14.04 LTS with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra -pedantic`
- Code must follow the Betty coding style
- No global variables allowed
- No more than 5 functions per file
- Dynamic memory allocation (`malloc`, `calloc`, etc.) is not allowed
- The function prototype must be included in a header file `palindrome.h`
- Header files should have include guards

## Prototype
```c
int is_palindrome(unsigned long n);
```
- `n`: The number to check
- Returns `1` if `n` is a palindrome, otherwise returns `0`

## Usage
### Compilation
```sh
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
```

### Example Execution
```sh
./palindrome 1
1 is a palindrome.

./palindrome 11
11 is a palindrome.

./palindrome 112
112 is not a palindrome.

./palindrome 121
121 is a palindrome.

./palindrome 12345678987654321
12345678987654321 is a palindrome.

./palindrome 123456789987654321
123456789987654321 is a palindrome.

./palindrome 1234567898654321
1234567898654321 is not a palindrome.
```

## Files
- `0-is_palindrome.c`: Implements the `is_palindrome` function
- `palindrome.h`: Contains the function prototype
- `0-main.c`: Example main file for testing

## Repository
GitHub repository: `holbertonschool-interview`

Directory: `palindrome_integer`

Files:
- `0-is_palindrome.c`
- `palindrome.h`

