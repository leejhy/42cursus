/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/02 15:24:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	size_t	total_len;

	total_len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			if (ft_checkform(*format, &total_len, ap) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(*format, &total_len) == -1)
				return (-1);
		}
		format++;
	}
	va_end(ap);
	return (total_len);
}

int	ft_checkform(char form_c, size_t *len, va_list ap)
{
	const char	*str_dec;

	str_dec = "0123456789";
	if (form_c == 'c')
		return (ft_putchar(va_arg(ap, int), len));
	if (form_c == 's')
		return (ft_putstr(va_arg(ap, char *), len));
	if (form_c == 'p')
		return (ft_putaddr(va_arg(ap, void *), len));
	if (form_c == 'd' || form_c == 'i')
		return (ft_putnbr_base(va_arg(ap, int), str_dec, 10, len));
	if (form_c == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), str_dec, 10, len));
	if (form_c == 'x' || form_c == 'X')
		return (ft_puthex(form_c, va_arg(ap, unsigned int), len));
	if (form_c == '%')
		return (ft_putchar(form_c, len));
	else
		return (-1);
	return (0);
}

int	ft_putaddr(void *addr, size_t *len)
{
	uintptr_t	addr_nb;
	char		*str_hex;

	str_hex = "0123456789abcdef";
	addr_nb = (uintptr_t)addr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	*len += 2;
	if (ft_print_addr(addr_nb, str_hex, len) == -1)
		return (-1);
	return (0);
}

int	ft_puthex(char form_c, unsigned long nb, size_t *len)
{
	const char	*str_uhex;
	const char	*str_lhex;

	str_uhex = "0123456789ABCDEF";
	str_lhex = "0123456789abcdef";
	if (form_c == 'x')
	{
		if (ft_putnbr_base(nb, str_lhex, 16, len) == -1)
			return (-1);
	}
	if (form_c == 'X')
	{
		if (ft_putnbr_base(nb, str_uhex, 16, len) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_addr(uintptr_t nb, const char *base, size_t *len)
{
	if (nb >= 16)
		ft_print_addr(nb / 16, base, len);
	if (write(1, &base[nb % 16], 1) == -1)
		return (-1);
	*len += 1;
	return (0);
}
