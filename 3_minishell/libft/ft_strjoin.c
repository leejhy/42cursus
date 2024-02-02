/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:40:49 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/07 23:50:17 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1len = ft_strlen(s1);
	const size_t	s2len = ft_strlen(s2);
	size_t			iter;
	char			*res;

	res = ft_calloc(s1len + s2len + 1, sizeof(char));
	if (!res)
		return (res);
	iter = 0;
	while (iter < s1len || iter < s2len)
	{
		if (iter < s1len)
			res[iter] = s1[iter];
		if (iter < s2len)
			res[s1len + iter] = s2[iter];
		iter++;
	}
	return (res);
}
