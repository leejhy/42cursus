/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:42:06 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 17:21:02 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char put, int fd)
{
	write(fd, &put, 1);
}

void	ft_recursion(int nb, int fd)
{
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{	
			nb = nb * -1;
			ft_putchar('-', fd);
		}
		if (nb < 10)
			ft_putchar(nb + '0', fd);
		if (nb > 9)
		{
			ft_recursion(nb / 10, fd);
			ft_recursion(nb % 10, fd);
		}
	}	
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_recursion(n, fd);
}
