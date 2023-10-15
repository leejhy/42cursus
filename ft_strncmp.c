/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:58:21 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 20:52:33 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while ((*(temp_s1 + i) && *(temp_s2 + i)) && (i < n))
	{	
		if (*(temp_s1 + i) != *(temp_s2 + i))
			return (*(temp_s1 + i) - *(temp_s2 + i));
		i++;
	}
	if (i == n)
		return (0);
	return (*(temp_s1 + i) - *(temp_s2 + i));
}
