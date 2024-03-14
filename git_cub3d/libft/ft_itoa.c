/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:22:07 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/14 09:34:37 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_arr(char *arr, long long n, int index)
{
	if (n < 0)
	{
		n *= -1;
		arr[0] = '-';
	}
	else if (n == 0)
	{
		arr[0] = '0';
	}
	while (n > 0)
	{
		arr[index--] = (n % 10) + 48;
		n /= 10;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char		*arr;
	long long	num;
	int			size;

	size = 1;
	num = (long long)n;
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	num /= 10;
	while (num)
	{
		num /= 10;
		size++;
	}
	arr = malloc(sizeof(char) * (size + 1));
	if (arr == NULL)
		return (0);
	arr[size] = '\0';
	return (ft_itoa_arr(arr, (long long)n, size - 1));
}
