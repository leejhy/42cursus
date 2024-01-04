/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:17 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/04 22:23:41 by junhylee         ###   ########.fr       */
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

void	int_to_idx(t_stack **head_a, int *arr, int arr_cnt)
{
	t_stack	*temp;
	int		i;

	if (head_a == NULL || *head_a == NULL)
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
	if (pos_a->size <= 5)
		ft_hard_sort(pos_a, pos_b);
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
	t_stack		*a;
	// t_stack		*b;
	t_pos		*pos_a;
	t_pos		*pos_b;

	ft_pos_set(&pos_a, &pos_b);//ok
	// printf("%p %p\n", pos_a, pos_b);
	// printf("%d %d\n", pos_a->size, pos_b->size);
	// a = pos_a->front;
	// b = pos_b->rear;
	if (is_errors(argc))
		return (0);
	nb_arr = ft_parsing(argc, argv);
	// if (!nb_arr)
	// {
	// 	printf("Error\n");
	// 	return (0);
	// }
	ft_makestack(&(pos_a->front), nb_arr, argc - 1);
	ft_connect_pos(&pos_a);//ok
	int_to_idx(&(pos_a->front), nb_arr, argc - 1);//ok
	// free(nb_arr);
	// a = pos_a->front;
	// if (!a || !pos_a || !nb_arr)
	if (!pos_a || !nb_arr)
	{
		printf("Error\n");
		return (0);
	}
	push_swap(pos_a, pos_b); //단일 포인터로도 바꿔보기 ok
	a = pos_a->front;
	while (a != NULL)
	{
		printf("%d\n", a->nb);
		// if (head_A->prev != NULL)
		// 	printf("prev :%d\n",head_A->prev->nb);
		a = a->next;
	}
	// printf("=========b=======\n");
	// b = pos_b->front;
	// while (b != NULL)
	// {
	// 	printf("%d\n", b->nb);
	// 	b = b->next;
	// }
	// printf(" size %d\n", pos_A->size);
	// printf(" size %d\n", pos_B->size);
	// printf("stack B : %d\n", head_B->nb);
	// printf("stack B : %d\n", head_B->next->nb);
	exit (0); // int arr등 아직 안쓴 애들도 있음
}
