/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:12:06 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 06:22:16 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	iter;

	res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (res);
	iter = 0;
	while (s[iter])
	{
		res[iter] = f(iter, s[iter]);
		iter++;
	}
	return (res);
}
