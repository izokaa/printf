#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>



#define UNUSED(x) (void)(x)

#define BUFFER_SIZE 1024



/* FLAGS */

#define F_MINUS 1

#define F_PLUS 2

#define F_ZERO 4

#define F_HASH 8

#define F_SPACE 16



/* SIZES */

#define S_SHORT 1

#define S_LONG 2



/**
 * struct f_frmat 
 *
 * @caracter: Caracter format.
 * @funct: format function.
 */

struct f_frmat

{

char caracter;

int (*funct)(va_list, char[], int, int, int, int);

};




/**
 * typedef struct f_frmat format_func - Struct op
 *
 * @caracter: The caracter format.
 * @funct: The format function.
 */

typedef struct f_frmat format_func;



int _printf(const char *format, ...);

int handle_convertion(const char *strg, int *i,

va_list list, char buffer[], int flags, int width, int precision, int size);



/****************** FUNCTIONS ******************/



/* Funtions to print chars and strings */

int print_char(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* Functions to print numbers */

int print_int(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_binary(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char buffer[],

int flags, int width, int precision, int size);

int print_hexa_uppercase(va_list types, char buffer[],

int flags, int width, int precision, int size);



int print_hexa(va_list types, char map_to[],

char buffer[], int flags, char flag_ch, int width, int precision, int size);



/*  print non printable characters */

int print_non_printable(va_list types, char buffer[],

int flags, int width, int precision, int size);



/*  print memory address */

int print_pointer(va_list types, char buffer[],

int flags, int width, int precision, int size);



/*  handle other specifiers */

int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);



/*   print string in reverse*/

int print_reverse(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* print a string in rot 13*/

int print_rot13string(va_list types, char buffer[],

int flags, int width, int precision, int size);



/* width handlers */

int handle_write_char(char c, char buffer[],

int flags, int width, int precision, int size);

int write_number(int is_positive, int index, char buffer[],

int flags, int width, int precision, int size);

int write_num(int index, char bff[], int flags, int width, int precision,

int length, char padding, char extra_char);

int write_pointer(char buffer[], int index, int length,

int width, int flags, char padding, char extra_char, int padd_start);



int write_unsigned(int is_negative, int index,

char buffer[],

int flags, int width, int precision, int size);



/**************** UTILS ****************/

int is_printable(char);

int append_hex(char, char[], int);

int is_digit(char);



long int convert_size_number(long int num, int size);

long int convert_size_unsigned(unsigned long int num, int size);



#endif 
