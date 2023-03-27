#include "main.h"
/**
 * get_width - extracts the width specifier from a printf format string
 * @format: the format string
 * @i: a pointer to the current index in the format string
 * @list: the va_list for the argument list
 *
 * Return: the width specifier, or 0 if not found
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (isdigit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;

			int arg_width = va_arg(list, int);

			if (arg_width >= 0)
			{
				width = arg_width;
			}
			break;
		}
		else
		{
			break;
		}
	}

	*i = curr_i - 1;

	return (width);
}
