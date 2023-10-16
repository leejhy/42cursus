/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:47 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/16 20:38:38 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	cnt;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle)
		return ((char *)haystack);
	if (!haystack)
		return (NULL);
	while (i < len)
	{
		cnt = 0;
		while (i + cnt < len && *(haystack + i + cnt) == *(needle + cnt))
			cnt++;
		if (cnt == needle_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// ft_strnstr(0x107d2fda0: "", "", 0): expected: 0x107d2fda0, yours: 0x0
// Error in test 4: ft_strnstr(0x107d2fda0: "", "", 1): expected: 0x107d2fda0, yours: 0x0
// Error in test 5: ft_strnstr(0x107d2fda0: "", "", 2)