/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:23:51 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 11:04:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd != -1)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			if (-(n / 10) > 0)
				ft_putnbr_fd(-(n / 10), fd);
			ft_putchar_fd((char)(-(n % 10) + '0'), fd);
		}
		else
		{
			if ((n / 10) > 0)
				ft_putnbr_fd((n / 10), fd);
			ft_putchar_fd((char)((n % 10) + '0'), fd);
		}
	}
}
