#include "main.h"
/************************* WRITE HANDLE *************************/

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[],

int flags, int width, int precision, int size)

{ /* char is stored at left and paddind at buffer's right */

int i = 0;

char padding = ' ';



UNUSED(precision);

UNUSED(size);



if (flags & F_ZERO)

padding = '0';



buffer[i++] = c;

buffer[i] = '\0';



if (width > 1)

{

buffer[BUFFER_SIZE - 1] = '\0';

for (i = 0; i < width - 1; i++)

buffer[BUFFER_SIZE - i - 2] = padding;



if (flags & F_MINUS)

return (write(1, &buffer[0], 1) +

write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));

else

return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +

write(1, &buffer[0], 1));

}



return (write(1, &buffer[0], 1));

}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @index: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int write_number(int is_negative, int index, char buffer[],

int flags, int width, int precision, int size)

{

int length = BUFFER_SIZE - index - 1;

char padding = ' ', extra_ch = 0;



UNUSED(size);



if ((flags & F_ZERO) && !(flags & F_MINUS))

padding = '0';

if (is_negative)

extra_ch = '-';

else if (flags & F_PLUS)

extra_ch = '+';

else if (flags & F_SPACE)

extra_ch = ' ';



return (write_num(index, buffer, flags, width, precision,

length, padding, extra_ch));

}
 
 /**
 * write_num - Write a number using a bufffer
 * @index: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padding: Padding char
 * @extra_char: Extra char
 *
 * Return: Number of printed chars.
 */

int write_num(int index, char buffer[],

int flags, int width, int prec,

int length, char padding, char extra_char)

{

int i, padd_start = 1;



if (prec == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0' && width == 0)

return (0); /* printf(".0d", 0)  no char is printed */

if (prec == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')

buffer[index] = padding = ' '; /* width is displayed with padding ' ' */

if (prec > 0 && prec < length)

padding = ' ';

while (prec > length)

buffer[--index] = '0', length++;

if (extra_char != 0)

length++;

if (width > length)

{

for (i = 1; i < width - length + 1; i++)

buffer[i] = padding;

buffer[i] = '\0';

if (flags & F_MINUS && padding == ' ')/* Asign extra char to left of buffer */

{

if (extra_char)

buffer[--index] = extra_char;

return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));

}

else if (!(flags & F_MINUS) && padding == ' ')/* extra char to left of buff */

{

if (extra_char)

buffer[--index] = extra_char;

return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));

}

else if (!(flags & F_MINUS) && padding == '0')/* extra char to left of padding */

{

if (extra_char)

buffer[--padd_start] = extra_char;

return (write(1, &buffer[padd_start], i - padd_start) +

write(1, &buffer[index], length - (1 - padd_start)));

}

}

if (extra_char)

buffer[--index] = extra_char;

return (write(1, &buffer[index], length));

}



/**

 * write_unsigned - Writes an unsigned number
 * @is_negative:  indicating if the num is negative
 * @index: Index of the  starts of the number in the buffer
 * @buffer: Array of chars
 * @flags: Flags 
 * @width: Width 
 * @precision: Precision 
 * @size: Size 
 *
 * Return: Number of written chars.
 */

int write_unsigned(int is_negative, int index,

char buffer[],

int flags, int width, int precision, int size)

{


int length = BUFFER_SIZE - index - 1, i = 0;

char padding = ' ';



UNUSED(is_negative);

UNUSED(size);



if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')

return (0); 



if (precision > 0 && precision < length)

padding = ' ';



while (precision > length)

{

buffer[--index] = '0';

length++;

}



if (!(flags & F_MINUS) && (flags & F_ZERO))

padding = '0';



if (width > length)

{

for (i = 0; i < width - length; i++)

buffer[i] = padding;



buffer[i] = '\0';



if (flags & F_MINUS) /* Asign an extra char to the left of buffer */

{

return (write(1, &buffer[index], length) + write(1, &buffer[0], i));

}

else /* Asign an extra char to the left of padding [padding>buffer]*/

{

return (write(1, &buffer[0], i) + write(1, &buffer[index], length));

}

}



return (write(1, &buffer[index], length));

}



/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padding: Char representing the padding
 * @extra_char: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */

int write_pointer(char buffer[], int index, int length,

int width, int flags, char padding, char extra_char, int padd_start)

{

int i;



if (width > length)

{

for (i = 3; i < width - length + 3; i++)

buffer[i] = padding;

buffer[i] = '\0';

if (flags & F_MINUS && padding == ' ')/* Asign extra char to left of buffer */

{

buffer[--index] = 'x';

buffer[--index] = '0';

if (extra_char)

buffer[--index] = extra_char;

return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));

}

else if (!(flags & F_MINUS) && padding == ' ')/* extra char to left of buffer */

{

buffer[--index] = 'x';

buffer[--index] = '0';

if (extra_char)

buffer[--index] = extra_char;

return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));

}

else if (!(flags & F_MINUS) && padding == '0')/* extra char to left of padding */

{

if (extra_char)

buffer[--padd_start] = extra_char;

buffer[1] = '0';

buffer[2] = 'x';

return (write(1, &buffer[padd_start], i - padd_start) +

write(1, &buffer[index], length - (1 - padd_start) - 2));

}

}

buffer[--index] = 'x';

buffer[--index] = '0';

if (extra_char)

buffer[--index] = extra_char;

return (write(1, &buffer[index], BUFFER_SIZE - index - 1));

}
