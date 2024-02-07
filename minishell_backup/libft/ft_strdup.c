/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:29:59 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 10:15:58 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	iter;
	char	*res;

	iter = 0;
	res = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!res)
		return (res);
	while (s1[iter])
	{
		res[iter] = s1[iter];
		iter++;
	}
	return (res);
}
