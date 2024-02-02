/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:31:11 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 08:25:27 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
	if ('0' <= uc && uc <= '9')
		return (1);
	return (0);
}
