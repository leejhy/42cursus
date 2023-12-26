/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:34:17 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/26 21:48:21 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (*(s + len))
// 		len++;
// 	return (len);
// }

int	is_errors(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	return (0);
}

void intToidx(t_pos *pos, t_stack *head_A, int *arr)
{
	
}

int	main(int argc, char **argv)
{
	size_t		i;
	long long	nb;
	int			*nb_arr;
	t_stack		*head_A;
	t_pos		*pos;

	i = 0;
	head_A = NULL;
	pos = NULL;
	if (is_errors(argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	nb_arr = ft_parsing(argc, argv);
	if (!nb_arr)
	{
		printf("Error\n");
		return (0);
	}
	ft_makestack(&head_A, nb_arr, argc - 1);
	init_pos(&pos, &head_A);
	intToidx(pos, head_A, nb_arr);
	if (!head_A || !pos)
	{
		printf("Error\n");
		return (0);
	}
	// for (int k = 0; k < argc - 1; k++)
	// 	printf("%d ", nb_arr[k]);
	while (head_A != NULL)
	{
		// printf("%d\n", head_A->nb);
		// if (head_A->prev != NULL)
			// printf("prev %d\n", head_A->prev->nb);
		head_A = head_A->next;
	}
	return (0);
}
