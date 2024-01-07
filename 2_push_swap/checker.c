/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:11:29 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 21:51:37 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	is_nl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_read_op(t_pos *pos_a, t_pos *pos_b)
{
	char	*str;
	char	buf;
	size_t	i;
	ssize_t	read_size;

	str = malloc(sizeof(char) * 10);
	if (!str)
		exit(1);
	i = 0;
	while (1)
	{
		read_size = read(0, &buf, 1);
		str[i] = buf;
		i += 1;
		str[i] = '\0';
		if (read_size <= 0)
			return (0);
		if (is_nl(str))
			break ;
	}
	ft_check_op(pos_a, pos_b, str);
	free(str);
	return (1);
}

void	ft_check_op(t_pos *pos_a, t_pos *pos_b, char *str)
{
	ft_check_error(str);
	ft_check_rotate(pos_a, pos_b, str);
	ft_check_swap(pos_a, pos_b, str);
	ft_check_push(pos_a, pos_b, str);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_pos	*pos_a;
	t_pos	*pos_b;
	int		*nb_arr;
	size_t	nb_cnt;

	if (argc <= 1)
		ft_error();
	init_pos(&pos_a, &pos_b);
	str = parsing(argc, argv);
	nb_cnt = ft_nb_cnt(str, ' ');
	nb_arr = str_to_nbarr(str, nb_cnt);
	ft_makestack(&(pos_a->front), nb_arr, nb_cnt);
	set_pos_a(&pos_a);
	int_to_idx(&(pos_a->front), nb_arr, nb_cnt);
	while (1)
	{
		if (ft_read_op(pos_a, pos_b) == 0)
			break ;
	}
	check_sorted(pos_a->front, pos_b);
	ft_frees(nb_arr, str, pos_a, pos_b);
	return (0);
}
