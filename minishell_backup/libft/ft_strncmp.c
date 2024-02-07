/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:41:25 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 05:45:55 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	iter;

	iter = 0;
	while (iter + 1 < n && s1[iter] == s2[iter] && s1[iter] && s2[iter])
		iter++;
	if (n == 0)
		return (0);
	return ((int)((unsigned char)s1[iter] - (unsigned char)s2[iter]));
}
