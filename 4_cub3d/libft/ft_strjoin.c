/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:05:04 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/11 17:47:40 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc(sizeof(char), (size + 1));
	if (result == NULL)
		return (0);
	if (s1 != 0)
		ft_strlcat(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, size + 1);
	return (result);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	result = ft_calloc(sizeof(char), (size + 1));
	if (result == NULL)
	{
		if (s1 != 0)
			free(s1);
		return (0);
	}
	if (s1 != 0)
	{
		ft_strlcat(result, s1, ft_strlen(s1) + 1);
		free(s1);
	}
	ft_strlcat(result, s2, size + 1);
	return (result);
}
