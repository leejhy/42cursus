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
			format++;
			if (ft_formchar(*format, &total_len, ap) == -1)
				return (-1);
		}
		else
			write(1, format, 1);//ft_putchar
		format++;
		total_len++;
	}
	va_end(ap);
	return (total_len);
}

int	ft_formchar(char form_c, int *len, va_list ap)
{
	if (form_c == 'c')
		return (ft_putchar(va_arg(ap, char), len));
	if (form_c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (form_c == 'p')
		return (ft_putaddr(va_arg(ap, void *), len));
	if (form_c == 'd' || form_c == 'i')
		return (ft_putdec(va_arg(ap, int)));
	if (form_c == 'u')
		return (ft_putudec(va_arg(ap, unsigned int)));
	if (form_c == 'x' || form_c == 'X')
		return (ft_puthex(form_c, va_arg(ap, unsigned int), len));
	if (form_c == '%')
		*len = *len + printf("%c", form_c);//ft_putchar
	return 0;
}

int	ft_putaddr(uintptr_t addr, int *len)
{
	write(1, "0x", 2);
	len += 2;
	if (ft_puthex('p', addr, len) == -1)
		return (-1);
}

int	ft_puthex(char form_c, unsigned int nb, int *len)
{
	if (form_c == 'x')
		ft_putnbr_base(nb, "0123456789abcdef", 16, len);
	if (form_c == 'X' || form_c == 'p')//else 
		ft_putnbr_base(nb, "0123456789ABCDEF", 16, len);
	return (0);
}

int	ft_putnbr_base(long long nb, char *base, int base_len, int *len)
{
	if (nb < 0)
	{
		(*len)++;
		nb = nb * -1;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base, base_len, len);
	if (write(1, &base[nb % base_len], 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}
