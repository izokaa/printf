#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array 
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_oct - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags:  active flags
 * @width: get 
 * @precision: Precision
 * @size: Size 
 * Return: Number of chars printed
 */
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array 
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * print_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array 
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array 
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hex(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
