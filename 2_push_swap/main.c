/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:17 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/27 21:09:46 by junhylee         ###   ########.fr       */
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

void	pushswap(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	//if (pos_A->size < 4)
		// hard_sort;
	if (*head_A == NULL || (*pos_A)->size == 0)
		return ;
	if ((*pos_A)->size <= 5)
	{
		ft_hard_sort(head_A, pos_A, head_B, pos_B);
	}
	if (*pos_B != NULL)
	{
		if (*head_B == NULL || (*pos_B)->size == 0)
			return ;
	}
}

int	main(int argc, char **argv)
{
	int			*nb_arr;
	t_stack		*head_A;
	t_stack		*head_B;
	t_pos		*pos_A;
	t_pos		*pos_B;

	head_A = NULL;
	head_B = NULL;
	pos_A = NULL;
	pos_B = NULL;
	if (is_errors(argc))
		return (0);
	nb_arr = ft_parsing(argc, argv);
	if (!nb_arr)
	{
		printf("Error\n");
		return (0);
	}
	ft_makestack(&head_A, nb_arr, argc - 1);
	set_pos(&pos_A, &head_A);
	intToidx(&head_A, nb_arr, argc - 1);
	// free(nb_arr);
	if (!head_A || !pos_A)
	{
		printf("Error\n");
		return (0);
	}
	pushswap(head_A, pos_A, head_B, pos_B);
	while (head_A != NULL)
	{
		printf("%d\n", head_A->nb);
		// if (head_A->prev != NULL)
		// 	printf("prev :%d\n",head_A->prev->nb);
		head_A = head_A->next;
	}
	printf(" size %d\n", pos_A->size);
	printf(" size %d\n", pos_B->size);
	printf("stack B : %d\n", head_B->nb);
	printf("stack B : %d\n", head_B->next->nb);
	exit (0); // int arr등 아직 안쓴 애들도 있음
}
