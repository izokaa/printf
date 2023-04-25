#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @format_func: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array .
 * @flags: Active flags
 * @width: get width.
 * @precision: Precision
 * @size: Size
 * Return: 1 or 2;
 */
int handle_print(const char *format_func, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_function fmt_types[] = {
		{'c', print_chars}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octa}, {'x', print_hexadec},
		{'X', print_hexadec_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].arg != '\0'; i++)
		if (format_func[*ind] == fmt_types[i].arg)
			return (fmt_types[i].formatter(list, buffer, flags, width, precision, size));

	if (fmt_types[i].arg == '\0')
	{
		if (format_func[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format_func[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format_func[*ind] != ' ' && format_func[*ind] != '%')
				--(*ind);
			if (format_func[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format_func[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
