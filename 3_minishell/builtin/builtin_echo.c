/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/11 15:13:28 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	is_n_flag(char *str)
{
	const int	size = ft_strlen(str);
	int			cnt_n;
	int			idx;

	cnt_n = 0;
	idx = 0;
	if (size == 0)
		return (FALSE);
	if (str[0] != '-')
		return (FALSE);
	if (size == 1)
		return (FALSE);
	while (str[idx])
	{
		if (str[idx] == 'n')
			cnt_n++;
		idx++;
	}
	return (cnt_n == size - 1);
}

int	builtin_echo(int argc, char **argv)
{
	int	flag;
	int	idx;

	idx = 1;
	flag = TRUE;
	while (idx < argc)
	{
		if (flag == TRUE)
			flag = is_n_flag(argv[idx]);
		if (flag == FALSE)
		{
			ft_putstr_fd(argv[idx], 1);
			if (idx != argc - 1)
				ft_putchar_fd(' ', 1);
		}
		idx++;
	}
	if (argc == 1 || !is_n_flag(argv[1]))
		ft_putchar_fd('\n', 1);
	return (0);
}
