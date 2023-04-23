#include "main.h"
/**
 * handle_convertion - Prints an argument based on the type
 * @strg:  string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @curr_index: current caracter index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_convertion(const char *strg, int *curr_index, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int i, write_lenght = 0, printed_chars = -1;
format_func format_types[] = {
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_uppercase}, {'p', print_pointer}, {'S', print_non_printable},
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary}
};
for (i = 0; format_types[i].caracter != '\0'; i++)
if (strg[*curr_index] == format_types[i].caracter)
return (format_types[i].funct(list, buffer, flags, width, precision, size));
if (format_types[i].caracter == '\0')
{
if (strg[*curr_index] == '\0')
return (-1);
write_lenght += write(1, "%%", 1);
if (strg[*curr_index - 1] == ' ')
write_lenght += write(1, " ", 1);
else if (width)
{
--(*curr_index);
while (strg[*curr_index] != ' ' && strg[*curr_index] != '%')
--(*curr_index);
if (strg[*curr_index] == ' ')
--(*curr_index);
return (1);
}
write_lenght += write(1, &strg[*curr_index], 1);
return (write_lenght);
}
return (printed_chars);
}
