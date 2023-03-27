#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - A custom implementation of the printf function
 * @format: A character string that contains zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char c, *s;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
					c = (char) va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;

				case 's':
					s = va_arg(args, char *);
					while (*s != '\0')
					{
						write(1, s, 1);
						s++;
						count++;
					}
					break;

				case '%':
					write(1, "%", 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);

	return (count);
}
