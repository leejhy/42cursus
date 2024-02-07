/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:13:56 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/13 16:04:55 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	byte;

	byte = count * size;
	if (size != 0 && byte / size != count)
		return (0);
	res = malloc(count * size);
	if (!res)
		return (res);
	ft_bzero(res, count * size);
	return (res);
}
