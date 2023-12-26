/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:20:39 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/02 15:23:40 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

int	ft_putstr(char *str, size_t *len)
{
	size_t	s_len;

	if (str == NULL)
	{
		*len += 6;
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (0);
	}
	s_len = ft_strlen(str);
	if (write(1, str, s_len) == -1)
		return (-1);
	*len += s_len;
	return (0);
}

int	ft_putchar(char c, size_t *len)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*len += 1;
	return (0);
}

int	ft_putnbr_base(long nb, const char *base, int base_len, size_t *len)
{
	if (nb < 0)
	{
		if (base_len == 10)
		{
			if (write(1, "-", 1) == -1)
				return (-1);
			(*len)++;
		}
		nb = nb * -1;
	}
	if (nb >= base_len)
	{
		if (ft_putnbr_base(nb / base_len, base, base_len, len) == -1)
			return (-1);
	}
	if (write(1, &base[nb % base_len], 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}
