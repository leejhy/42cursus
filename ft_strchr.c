/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:48:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/16 16:46:58 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	temp_c;

	temp_c = (char)c;
	while (*s)
	{
		if (*s == temp_c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && temp_c == '\0')
		return ((char *)s);
	return (NULL);
}
