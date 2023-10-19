/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:18:39 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/19 18:22:00 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_input(long long n, char *str)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	while (n > 0)
	{
		*(str + i) = (n % 10) + '0';
		i++;
		n /= 10;
	}
	if (sign == 1)
	{
		*(str + i) = '-';
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

static char	*ft_rev(char *str, int len)
{
	char	*rev;
	int		i;

	i = 0;
	rev = malloc(sizeof(char) * (len + 1));
	if (!rev)
	{
		free(str);
		return (NULL);
	}
	while (i < len)
	{
		rev[i] = str[len - (i + 1)];
		i++;
	}
	free(str);
	rev[i] = '\0';
	return (rev);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		*str = '0';
		*(str + 1) = '\0';
		return (str);
	}
	len = ft_count(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_input(n, str);
	str = ft_rev(str, len);
	return (str);
}
