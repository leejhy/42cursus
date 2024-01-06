/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:17 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/06 19:19:06 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_errors(int argc)
{
	if (argc <= 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	int_to_idx(t_stack **head_a, int *arr, int arr_cnt)
{
	t_stack	*temp;
	int		i;

	if (head_a == NULL || *head_a == NULL)
		return ;
	if (arr == NULL)
		return ;
	temp = *head_a;
	while (temp != NULL)
	{
		i = 0;
		while (i < arr_cnt)
		{
			if (arr[i] == temp->nb)
			{
				temp->nb = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	push_swap(t_pos *pos_a, t_pos *pos_b)
{
	if (pos_a->size == 0)
		return ;
	if (is_sorted(pos_a->front))
		return ;
	if (pos_a->size <= 3)
		ft_hard_sort(pos_a);
	else
		greedy(pos_a, pos_b);
}

void	ft_pos_set(t_pos **pos_a, t_pos **pos_b)
{
	t_pos	*temp_a;
	t_pos	*temp_b;

	*pos_a = malloc(sizeof(t_pos));
	*pos_b = malloc(sizeof(t_pos));
	temp_a = *pos_a;
	temp_b = *pos_b;
	if (!(*pos_a) || !(*pos_b))
		exit(0);
	temp_a->front = NULL;
	temp_b->front = NULL;
	temp_a->rear = NULL;
	temp_b->rear = NULL;
	temp_a->size = 0;
	temp_b->size = 0;
}

int	main(int argc, char **argv)
{
	int			*nb_arr;
	t_pos		*pos_a;
	t_pos		*pos_b;

	ft_pos_set(&pos_a, &pos_b);
	if (is_errors(argc))
		return (0);
	nb_arr = ft_parsing(argc, argv);
	// if (!nb_arr)
	// {
	// 	printf("Error\n");
	// 	return (0);
	// }
	ft_makestack(&(pos_a->front), nb_arr, argc - 1);
	ft_connect_pos(&pos_a);
	int_to_idx(&(pos_a->front), nb_arr, argc - 1);
	if (!pos_a || !nb_arr)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap(pos_a, pos_b);
	exit (0);
}
