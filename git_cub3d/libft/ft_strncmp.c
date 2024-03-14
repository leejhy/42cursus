/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:41:35 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/14 15:04:17 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (*temp1 == *temp2 && n)
	{
		if (*temp1 == '\0' || *temp2 == '\0')
			break ;
		temp1++;
		temp2++;
		n--;
	}
	if (n <= 0)
		return (0);
	return (*temp1 - *temp2);
}
