/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:29:15 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 11:24:33 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	iter;

	iter = 0;
	while (s[iter] || (char)c == 0)
	{
		if (s[iter] == (char)c)
			return ((char *)&s[iter]);
		iter++;
	}
	return (0);
}
