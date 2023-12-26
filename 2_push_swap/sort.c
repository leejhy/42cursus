/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:46:15 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/26 21:31:59 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *arr, int arr_cnt)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_cnt)
	{
		j = i;
		while (j < arr_cnt)
		{
			if (i != j && arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}