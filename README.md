# 42-ft_printf

## Introduction
ft_printf is a project focused on recreating the renowned printf function from the C Standard Library.

This project provides a comprehensive understanding of the C programming language, 

especially about variadic functions and memory management.

## Features
A lightweight implementation of the printf function in C.

Supports the following conversions:

%c: Print a single character.

%s: Print a string.

%p: Print a void * pointer argument in hexadecimal format.

%d: Print a decimal (base 10) number.

%i: Print an integer in base 10.

%u: Print an unsigned decimal (base 10) number.

%x: Print a number in hexadecimal (base 16) lowercase format.

%X: Print a number in hexadecimal (base 16) uppercase format.

%%: Print a percent sign.

## Installation
```sh
git clone https://github.com/Asrasal47/42-ft_printf.git
```
```sh
cd 42-ft_printf && make
```
This will compile the library and generate a libftprintf.a file.

## Usage
Include the header file (ft_printf.h) in your C project:
>#include "ft_printf.h"

When compiling your project, link with the libftprintf.a file:

```sh
gcc your_c_file.c -L. -lftprintf -o your_program_name
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
