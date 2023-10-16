/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:16:36 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 18:35:06 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		cnt;

	cnt = 0;
	while (c > 255)
		c -= 255;
	while (*s)
	{
		if (*s == c)
		{
			temp = (char *)s;
			cnt++;
		}
		s++;
	}
	if (!cnt && c == '\0')
		return ((char *)s);
	if (!cnt && c != '\0')
		return (NULL);
	return (temp);
}
