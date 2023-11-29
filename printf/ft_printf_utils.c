/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:20:39 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/29 16:39:40 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (NULL);
	while (*(s + len))
		len++;
	return (len);
}

void	ft_recursion(long long nb, int fd)
{
	long long	put;

	if (nb < 0)
	{
		nb = nb * -1;
		write(fd, "-", 1);
	}
	if (nb < 10)
	{
		put = nb + '0';
		write(fd, &put, 1);
	}
	if (nb >= 10)
	{
		ft_recursion(nb / 10, fd);
		ft_recursion(nb % 10, fd);
	}
}

void	ft_putnbr_fd(long long n, int fd)
{
	ft_recursion(n, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	write(fd, s, s_len);
}
int	ft_putchar(char c, int *len)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*len += 1;
	return (0);
}