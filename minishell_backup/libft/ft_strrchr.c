/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:34:02 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 06:59:01 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		uc = (const char)c;
	const size_t	ssize = ft_strlen(s);
	size_t			iter;

	iter = 0;
	while (iter <= ssize)
	{
		if (s[ssize - iter] == uc)
			return ((char *)&s[ssize - iter]);
		iter++;
	}
	return (0);
}
