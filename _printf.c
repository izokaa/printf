#include "main.h"
void print_buffer(char buffer[], int *buffer_index);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{

int i, printed = 0, printed_chars = 0;

int flags, width, precision, size, buffer_index = 0;

va_list vlist;

char buffer[BUFFER_SIZE];

if (format == NULL)

return (-1);

va_start(vlist, format);

for (i = 0; format && format[i] != '\0'; i++)

{

if (format[i] != '%')

{

buffer[buffer_index++] = format[i];

if (buffer_index == BUFFER_SIZE)

print_buffer(buffer, &buffer_index);


printed_chars++;

}

else

{

print_buffer(buffer, &buffer_index);

flags = get_flags(format, &i);

width = get_width(format, &i, vlist);

precision = get_precision(format, &i, vlist);

size = get_size(format, &i);

++i;

printed = handle_convertion(format, &i, vlist, buffer,

flags, width, precision, size);

if (printed == -1)

return (-1);

printed_chars += printed;

}

}



print_buffer(buffer, &buffer_index);



va_end(vlist);



return (printed_chars);

}



/**
 * print_buffer - Prints the contents of a buffer if it exist
 * @buffer: Array of chars
 * @buffer_index: Index to add next char that represents the length.
 */

void print_buffer(char buffer[], int *buffer_index)

{

if (*buffer_index > 0)

write(1, &buffer[0], *buffer_index);



*buffer_index = 0;

}
