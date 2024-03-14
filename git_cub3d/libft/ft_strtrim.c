/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:23:00 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/14 17:21:00 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	while (set[i] != '\0')
	{
		if (s1[start] == set[i] && s1[start] != '\0')
		{
			start++;
			i = 0;
		}
		else
			i++;
	}
	return (start);
}

size_t	ft_end(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;

	end = ft_strlen(s1);
	i = 0;
	while (set[i] != '\0')
	{
		if (end > 0 && s1[end - 1] == set[i])
		{
			end--;
			i = 0;
		}
		else
			i++;
	}
	return (end);
}

char	*ft_s1_trim_set(char const *s1, char *temp, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		temp[i] = s1[start];
		start++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*temp;

	start = ft_start(s1, set);
	if (s1[start] == '\0')
	{
		temp = malloc(sizeof(char) * 1);
		if (!temp)
			return (0);
		temp[0] = '\0';
		return (temp);
	}
	end = ft_end(s1, set);
	if (end == 0)
		return ("\0");
	temp = malloc(sizeof(char) * (end - start + 1));
	if (temp == NULL)
		return (0);
	return (ft_s1_trim_set(s1, temp, start, end));
}
