/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:42:06 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/19 18:35:33 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursion(long long nb, int fd)
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

void	ft_putnbr_fd(int n, int fd)
{
	ft_recursion(n, fd);
}
