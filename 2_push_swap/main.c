/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:17 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/03 21:43:36 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_errors(int argc)
{
	if (argc <= 1)
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}

void	intToidx(t_stack **head_A, int *arr, int arr_cnt)
{
	t_stack	*temp;
	int		i;

	if (head_A == NULL || *head_A == NULL)
		return ;
	temp = *head_A;
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

void	push_swap(t_stack **a, t_pos **pos_a, t_stack **b, t_pos **pos_b)
{
	if (*a == NULL || (*pos_a)->size == 0)
		return ;
	if (is_sorted(a))
		return ;
	if ((*pos_a)->size <= 5)
		ft_hard_sort(a, pos_a, b, pos_b);
	else
		greedy(a, pos_a, b, pos_b);
}

int	main(int argc, char **argv)
{
	int			*nb_arr;
	t_stack		*a;
	t_stack		*b;
	t_pos		*pos_a;
	t_pos		*pos_b;

	a = NULL;
	b = NULL;
	pos_a = NULL;
	pos_b = NULL;
	if (is_errors(argc))
		return (0);
	nb_arr = ft_parsing(argc, argv);
	// if (!nb_arr)
	// {
	// 	printf("Error\n");
	// 	return (0);
	// }
	ft_makestack(&a, nb_arr, argc - 1);
	set_pos(&pos_a, &a);
	intToidx(&a, nb_arr, argc - 1);
	// free(nb_arr);
	if (!a || !pos_a || !nb_arr)
	{
		printf("Error\n");
		return (0);
	}
	push_swap(&a, &pos_a, &b, &pos_b);
	while (a != NULL)
	{
		printf("%d\n", a->nb);
		// if (head_A->prev != NULL)
		// 	printf("prev :%d\n",head_A->prev->nb);
		a = a->next;
	}
	// printf(" size %d\n", pos_A->size);
	// printf(" size %d\n", pos_B->size);
	// printf("stack B : %d\n", head_B->nb);
	// printf("stack B : %d\n", head_B->next->nb);
	exit (0); // int arr등 아직 안쓴 애들도 있음
}
