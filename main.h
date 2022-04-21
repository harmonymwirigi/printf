#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>

/**
 *  * struct print - structure for printing various types
 *   * @t: type to print
 *    * @f: function to print
 *     */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;
int (*check_format(const char *format))(va_list)
{
	int i = 0;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};
	for (; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
		break;
	}
	return (p[i].f);
}

/**
 *  * _printf - function for format printing
 *   * @format: list of arguments to printing
 *    * Return: Number of characters to printing
 *     */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, counter = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				1 += 2;
				counter += f(ap);
				continue;
			}
		}
		i++;
	}
	va_en(ap);
	return (counter);
}
int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_f(va_list f);
int print_e(va_list e);
int print_g(va_list g);
int print_l(va_list l);
int print_0(va_list zero);
int print_h(va_list h);
int print_u(va_list u);
int print_b(va_list b);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_R(va_list R);
int print_add(va_list add);
int print_less(va_list less);
int print_space(va_list space);
int print_sharp(va_list sharp);

#endif  /* _MAIN_H */
