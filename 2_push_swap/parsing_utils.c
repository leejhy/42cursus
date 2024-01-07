/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:40:59 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 15:28:31 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nb_cnt(char *str, char sep)
{
	int	i;
	int	len;
	int	nb_cnt;

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
			exit(1);
	}
	return (nb_cnt);
}

int	ft_arg_len(char **argv, int arg_cnt)
{
	int		i;
	int		len;
	int		total_len;
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

void	ft_strcat(char *dest, char *str_arg, int *idx)
{
	int	i;

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
