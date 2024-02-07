/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:37:20 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 15:45:08 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	iter;
	size_t	ssize;
	char	*res;

	ssize = ft_strlen(s);
	iter = 0;
	if (len + start > ssize)
		len = ssize - start;
	if (start >= ssize)
		len = 0;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (res);
	while (iter < len && start < ssize && s[iter + start])
	{
		res[iter] = s[start + iter];
		iter++;
	}
	return (res);
}
