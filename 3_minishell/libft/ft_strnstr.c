/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:27:51 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 08:54:47 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	needle_size = ft_strlen(needle);
	size_t			iter;

	if (!needle[0])
		return ((char *)haystack);
	iter = 0;
	while (len > 0 && haystack[iter] && iter + needle_size - 1 < len)
	{
		if (ft_strncmp(&haystack[iter], needle, needle_size) == 0)
			return ((char *)&haystack[iter]);
		iter++;
	}
	return (0);
}
