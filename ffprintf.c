
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(char const *format, ...)
{
	va_list ap;
	size_t	total_len;

	total_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_formchar(format, &total_len, ap) == -1)
				return (-1);
		}
		else
			printf("%c", *format);//ft_putchar
		format++;
		total_len++;
	}
	return (total_len);
}

int	ft_formchar(char const form_c, int *len, va_list ap)
{
	if (form_c == 'c')
		return (ft_putchar(va_arg(ap, char), len));//얘를 char형으로 받아서 출력
	if (form_c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (form_c == 'p')
		return (ft_putaddr(va_arg(ap, unsigned long long)));
	if (form_c == 'd' || form_c == 'i')
		return (ft_putdec(va_arg(ap, int)));
	if (form_c == 'u')
		return (ft_putudec(va_arg(ap, unsigned int)));
	if (form_c == 'x' || form_c == 'X')
		return (ft_puthex(va_arg(ap, unsigned int)));
	if (form_c == '%')
		*len = *len + printf("%c", form_c);//ft_putchar
}