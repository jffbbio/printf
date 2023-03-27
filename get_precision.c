#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string
 * @list: va_list of arguments
 *
 * Return: The precision to use for printing
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_pos = *i + 1;
	int precision = -1;

/* Check if the precision is specified */
	if (format[curr_pos] != '.')
		return (precision);

	precision = 0;

/* Parse the precision */
	for (curr_pos += 1; format[curr_pos] != '\0'; curr_pos++)
	{
		if (isdigit(format[cur_pos]))
			precision = precision * 10 + format[curr_pos] - '0';
		else if (format[curr_pos] == '*')
		{
			curr_pos++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

/* Update the current position */
	*i = curr_pos - 1;

	return (precision);
}
