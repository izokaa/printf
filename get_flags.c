#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{

int j, curr_index;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
if (format[curr_index] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}
if (FLAGS_CH[j] == 0)
break;
}
*i = curr_index - 1;
return (flags);
}
