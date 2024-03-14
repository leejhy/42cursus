/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:34:34 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/09 16:03:14 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_same(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
		i++;
	if (s2[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	flag;
	size_t	hay_len;
	size_t	nee_len;

	hay_len = ft_strlen(haystack);
	nee_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (nee_len > hay_len || nee_len > len)
		return (0);
	flag = len - nee_len + 1;
	while (flag-- && *haystack != '\0')
	{
		if (*haystack == needle[0])
		{
			if (ft_str_same(haystack, needle))
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}

char	*ft_strnstr_rev(const char *haystack, const char *needle, size_t len)
{
	size_t	flag;
	size_t	hay_len;
	size_t	nee_len;

	hay_len = ft_strlen(haystack);
	nee_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (nee_len >= hay_len || nee_len > len)
		return (0);
	flag = len - nee_len + 1;
	hay_len -= nee_len;
	while (hay_len > 0 && flag-- && haystack[hay_len] != '\0')
	{
		if (haystack[hay_len] == needle[0])
		{
			if (ft_str_same(haystack + hay_len, needle))
				return ((char *)haystack);
		}
		hay_len--;
	}
	return (0);
}
