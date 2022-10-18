/*#include "main.h"

**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 *
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	va_list arg_list;
	if (format == NULL)
		return (-1);
	
	va_start(arg_list, format);
	*Calling parser function
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
*/
#include "main.h"

/**
 *  * t_char - print a character
 *   *@va:character
 *    *
 *     * Return: no return
 *      */
int t_char(va_list va)
{
		int c;

			c = va_arg(va, int);
				_putchar(c);
					return (1);
}
/**
 *  * t_string - print a string
 *   *@va: pointer to string
 *    *
 *     * Return: no return
 *      */
int t_string(va_list va)
{
		int i, j;
			char n[] = "(null)";
				char *s = va_arg(va, char *);

					if (s == NULL)
							{
										for (i = 0; n[i] != '\0'; i++)
														_putchar(n[i]);
												return (6);
													}
						for (j = 0; s[j] != '\0'; j++)
									_putchar(s[j]);
							return (j);
}
/**
 *  * print_number - Entry point
 *   *@va: the integer to print
 *    * Return: no return
 *     */
int print_number(va_list va)
{
		int i, len, r, l;
			unsigned int abs, num, numt;
				int n = va_arg(va, int);

					len = 0;
						i = 0;
							r = 1;
								l = 1;
									if (n < 0)
											{
														_putchar('-');
																len++;
																		abs = -n;
																			} else
																					{
																								abs = n;
																									}

																				num = abs;
																					while (num > 0)
																							{
																										num /= 10;
																												i++;
																													}

																						while (r < i)
																								{
																											l *= 10;
																													r++;
																														}
																							while (l >= 1)
																									{
																												numt = (abs / l) % 10;
																														_putchar(numt + '0');
																																len++;
																																		l /= 10;
																																			}
																								return (len);
}

/**
 *  * _printf - print output according to a format
 *   *@format: first argument
 *    *
 *     * Return: the number of characters printed(excluding the null byte)
 *      */
int _printf(const char *format, ...)
{
		int i = 0, j, len = 0, count;
			va_list valist;
				types difftypes[] = {{'c', t_char}, {'s', t_string}, {'d', print_number},
								     {'i', print_number}, {'b', binary}, {'u', print_unsigned},
								     			     {'x', hexa}, {'X', hexa_upper}, {'o', octal}, {'R', print_rot},
											     			     {'r', print_rev}, {'S', stringhexa}, {'p', pointer}};

					if (format == NULL || (format[0] == '%' && format[1] == 0))
								return (-1);
						va_start(valist, format);
							while (format != NULL && format[i])
									{
												if (format[i] != '%')
																len += _putchar(format[i]);
														else
																	{
																					i++;
																								if (format[i] == '%')
																													len += _putchar('%');
																											j = 0;
																														count = 0;
																																	while (j < 13)
																																					{
																																										if (format[i] == difftypes[j].t)
																																															{
																																																					len += difftypes[j].f(valist);
																																																										count = 1;
																																																															break; }
																																														j++; }
																																				if (!count && format[i] != '%')
																																								{
																																													len++;
																																																	len++;
																																																					_putchar('%');
																																																									_putchar(format[i]); }}
																i++; }
								va_end(valist);
									return (len);
}

