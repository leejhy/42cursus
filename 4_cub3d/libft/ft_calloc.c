/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:13:30 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/09 17:01:33 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(size * count);
	if (temp == NULL)
		return (0);
	while (i < count * size)
	{
		temp[i++] = '\0';
	}
	return (temp);
}
