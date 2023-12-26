/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:46:15 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/26 19:49:40 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *arr, int arr_cnt)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < arr_cnt)
	{
		temp = arr[i];
		j = i - 1;
		while (temp < arr[j] && j >= 0)
		{
			if (temp < arr[j])
				arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
		i++;
	}
}