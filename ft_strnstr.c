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

// #include "libft.h"
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while ((i < n))
	{	
		if (*(temp_s1 + i) != *(temp_s2 + i))
			return (*(temp_s1 + i) - *(temp_s2 + i));
		i++;
	}
	return (*(temp_s1 + i) - *(temp_s2 + i));
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;

	i = 0;
	if (!needle || !*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*(haystack + i) && i < len)
	{
		if (*(haystack + i) == *needle)
		{
			if (ft_strncmp(haystack + i, needle, len - i))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	printf("%s\n", ft_strnstr("123456123","456",6));
	// printf("%s\n", ft_strnstr("w","", 1));
	// printf("%s\n", ft_strnstr("","", 2));
}
// ft_strnstr(0x107d2fda0: "", "", 0): expected: 0x107d2fda0, yours: 0x0
// Error in test 4: ft_strnstr(0x107d2fda0: "", "", 1): expected: 0x107d2fda0, yours: 0x0
// Error in test 5: ft_strnstr(0x107d2fda0: "", "", 2)