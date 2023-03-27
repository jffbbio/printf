#include "main.h"
/**
 * _printf - Prints formatted output to stdout.
 * @format: String containing format specifiers.
 *
 * Return: Number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFFER_SIZE];
	int buff_ind = 0, printed_chars = 0, i;

	va_start(list, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			i += print_format_specifier(buffer, &buff_ind, format + i, &list);

			if (i == -1)
				return (-1);

			printed_chars += i;
		}
		else
		{
			printed_chars++;
			print_char(buffer, format[i], &buff_ind);
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
