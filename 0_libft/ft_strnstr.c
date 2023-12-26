/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:47 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/19 18:37:07 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	cnt;
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*(haystack + i) && i + n_len <= len)
	{
		cnt = 0;
		if (*(haystack + i) == *needle)
		{
			while (cnt < n_len && *(haystack + i + cnt) == *(needle + cnt))
				cnt++;
			if (cnt == n_len)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
