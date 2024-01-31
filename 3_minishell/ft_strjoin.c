/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:52:41 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/31 20:00:29 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*str;
	char	*temp_s1;
	size_t	s1_len;

	temp_s1 = s1;
	s1_len = 0;
	while (s1 && s1[s1_len])
		s1_len++;
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = '\0';
	if (temp_s1)
		free(temp_s1);
	return (str - (s1_len + s2_len));
}