/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/29 17:05:55 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list ap;
	int	total_len;

	total_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;//format의 마지막 문자가 %이면 여기서 '\0'을 찍고
			if (*format == '\0')//아래 format++에서 segfault 방지
				break ;
			if (ft_checkform(*format, &total_len, ap) == -1)
			{
				va_end(ap);
				return (-1);
			}
		}
		else
			ft_putchar(*format, &total_len);
		format++;
		total_len++;
	}
	va_end(ap);
	return (total_len);
}

int	ft_checkform(char form_c, int *len, va_list ap)
{
	if (form_c == 'c')
		return (ft_putchar(va_arg(ap, char), len));
	if (form_c == 's')
		return (ft_putstr(va_arg(ap, char *), len));
	if (form_c == 'p')
		return (ft_putaddr(va_arg(ap, void *), len));
	if (form_c == 'd' || form_c == 'i')
		return (ft_putdec(va_arg(ap, int), len));
	if (form_c == 'u')
		return (ft_putdec(va_arg(ap, unsigned int), len));
	if (form_c == 'x' || form_c == 'X')
		return (ft_puthex(form_c, va_arg(ap, unsigned int), len));
	if (form_c == '%')
		return (ft_putchar(form_c));//ft_putchar
	else
		return (-1);
	return 0;
}

int	ft_putaddr(uintptr_t addr, int *len)
{
	write(1, "0x", 2);
	*len += 2;
	if (ft_puthex('p', addr, len) == -1)
		return (-1);
}

int	ft_putdec(int nb, int *len)
{
	ft_putnbr_base(nb, "0123456789", 10, len);
}

int	ft_puthex(char form_c, unsigned int nb, int *len)
{
	if (form_c == 'x')
		ft_putnbr_base(nb, "0123456789abcdef", 16, len);
	if (form_c == 'X' || form_c == 'p')//else 
		ft_putnbr_base(nb, "0123456789ABCDEF", 16, len);
	return (0);
}

