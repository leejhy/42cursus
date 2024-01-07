/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:40:59 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 21:28:11 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_nb_cnt(char *str, char sep)
{
	size_t	i;
	size_t	len;
	size_t	nb_cnt;

	i = 0;
	nb_cnt = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] && str[i] == sep)
			i += 1;
		if (str[i] != '\0')
			nb_cnt += 1;
		while (str[i] && str[i] != sep)
		{
			len += 1;
			i += 1;
		}
		if (len > 11)
			ft_error();
	}
	return (nb_cnt);
}

size_t	ft_arg_len(char **argv, size_t arg_cnt)
{
	size_t	i;
	size_t	len;
	size_t	total_len;
	char	*tmp_str;

	i = 1;
	total_len = 0;
	while (i <= arg_cnt)
	{
		len = 0;
		tmp_str = argv[i];
		if (*tmp_str == '\0')
			ft_error();
		while (tmp_str[len])
			len += 1;
		total_len += len;
		i++;
	}
	return (total_len);
}

void	ft_strcat(char *dest, char *str_arg, size_t *idx)
{
	size_t	i;

	i = 0;
	while (str_arg[i])
	{
		dest[*idx] = str_arg[i];
		*idx += 1;
		i += 1;
	}
	dest[*idx] = ' ';
	*idx += 1;
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

void	init_pos(t_pos **pos_a, t_pos **pos_b)
{
	t_pos	*temp_a;
	t_pos	*temp_b;

	*pos_a = malloc(sizeof(t_pos));
	if (!(*pos_a))
		failed_malloc();
	*pos_b = malloc(sizeof(t_pos));
	if (!(*pos_b))
		failed_malloc();
	temp_a = *pos_a;
	temp_b = *pos_b;
	temp_a->front = NULL;
	temp_b->front = NULL;
	temp_a->rear = NULL;
	temp_b->rear = NULL;
	temp_a->size = 0;
	temp_b->size = 0;
}
