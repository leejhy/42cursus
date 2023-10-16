/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:16:36 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/16 16:45:38 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	temp_c;
	int		cnt;

	temp_c = (char)c;
	cnt = 0;
	while (*s)
	{
		if (*s == temp_c)
		{
			temp = (char *)s;
			cnt++;
		}
		s++;
	}
	if (!cnt && temp_c == '\0')
		return ((char *)s);
	if (!cnt && temp_c != '\0')
		return (NULL);
	return (temp);
}
