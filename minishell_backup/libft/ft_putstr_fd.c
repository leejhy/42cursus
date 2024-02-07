/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:20:31 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 03:09:00 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	iter;

	iter = 0;
	if (fd != -1)
	{
		while (s[iter])
		{
			ft_putchar_fd(s[iter], fd);
			iter++;
		}
	}
}
