/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:33:22 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/14 17:16:53 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	row_size(char *str, char c)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\0')
			size++;
		if (str[i] == '\n')
			i++;
		else
		{
			while (str[i] != '\0' && str[i] != c)
				i++;
			if (str[i] == c)
				i++;
		}
	}
	return (size);
}

char	*make_arr(char *str, char c)
{
	size_t	len;
	char	*arr_small;
	size_t	i;

	len = 0;
	if (*(str + len) == '\n')
		len++;
	else
	{
		while (*(str + len) && *(str + len) != c)
			len++;
	}
	arr_small = (char *)malloc(sizeof(char) * (len + 1));
	if (arr_small == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		arr_small[i] = *(str + i);
		i++;
	}
	arr_small[i] = '\0';
	return (arr_small);
}

int	ft_free(char **arr, size_t index)
{
	if (arr[index] != NULL)
		return (0);
	while (index > 0)
	{
		free(arr[index]);
		index--;
	}
	free(arr[index]);
	free(arr);
	return (1);
}

char	**str_split(char **arr, char *str, char c)
{
	size_t	i;
	size_t	index;

	index = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i))
		{
			arr[index] = make_arr((str + i), c);
			if (ft_free(arr, index++))
				return (0);
			if (*(str + i) == '\n')
				i++;
			else
			{
				while (*(str + i) && *(str + i) != c)
					i++;
				if (*(str + i) == c)
					i++;
			}
		}
	}
	arr[index] = 0;
	return (arr);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	size_t	size;

	if (str == 0)
		return (0);
	size = row_size(str, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (0);
	return (str_split(arr, str, c));
}
