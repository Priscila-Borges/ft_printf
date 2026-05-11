*This project has been created as part of the 42 curriculum by pride-ol.*

# Description
The goal of the ft_printf project is to recode the standard C library function printf(). This project introduces Variadic Functions in C.

My implementation handles a variety of format specifiers and mimics the behavior of the original printf from the libc, managing the output to the standard output and returning the total number of characters printed.

## Supported Conversions
Specifier	Description

%c	Prints a single character.

%s	Prints a string (as defined by the common C convention).

%p	Prints the void * pointer argument in hexadecimal format.

%d	Prints a decimal (base 10) number.

%i	Prints an integer in base 10.

%u	Prints an unsigned decimal (base 10) number.

%x	Prints a number in hexadecimal (base 10) lowercase format.

%X	Prints a number in hexadecimal (base 10) uppercase format.

%%	Prints a percent sign.

# Instructions
Compilation

The project includes a Makefile that compiles the source files into a static library named libftprintf.a.

To compile the library, run:

Bash
``make``

Usage

To use the library in your own project, include the header in your C files and link the .a file during compilation:

Include the header:

#include "ft_printf.h"

Compile your program:

Bash
   ``cc main.c libftprintf.a -o my_program``

Execution

Run your binary as usual:

Bash
``./my_program``

# Algorithm and Data Structure

Algorithm Choice: The Dispatcher Pattern

The core algorithm follows a sequential parsing approach. The function iterates through the format string character by character.

Regular Characters: If the character is not %, it is sent directly to a output function.

Format Specifiers: When a % is detected, the algorithm "dispatches" the task to a helper function (check_format). This helper uses the subsequent character to determine which specialized function should handle the specific data type (integers, strings, hexadecimals, etc.).

Data Structure: Variadic Lists (va_list)
The primary data structure used is the va_list provided by <stdarg.h>.

Justification: Since the number and types of arguments passed to printf are unknown at compile time, va_list allows the program to navigate the stack frame and retrieve arguments dynamically. This is the only standard and efficient way to handle a variable number of arguments in C without manual memory/stack manipulation.

## Resources
Man printf(3) - The official Linux programmer's manual.

Variadic Functions in C - [geeks for geeks](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

Use of AI
Conceptual Learning: Explaining the mechanics of va_list, va_arg, and the memory promotion of types (e.g., why char is promoted to int in variadic functions).

Debugging: Assisting in identifying "edge cases" such as NULL strings or the behavior of %p on different operating systems.

Documentation: Assisting in the structure and drafting of this README file.