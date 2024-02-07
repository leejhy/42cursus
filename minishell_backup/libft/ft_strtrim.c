/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:12:30 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 13:56:57 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_iter;
	size_t	back_iter;
	char	*res;

	if (!s1)
		return (0);
	front_iter = 0;
	back_iter = ft_strlen(s1);
	if (back_iter > 0)
		back_iter--;
	while (front_iter <= back_iter && ft_strchr(set, s1[front_iter]))
		front_iter++;
	while (back_iter >= front_iter && ft_strchr(set, s1[back_iter]))
		back_iter--;
	res = ft_substr(s1, front_iter, back_iter - front_iter + 1);
	if (!res)
		return (0);
	return (res);
}
