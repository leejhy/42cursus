/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/04 21:44:03 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static size_t	ft_get_digit_size(long n)
{
	size_t	size;

	if (n > 0)
		n *= -1;
	size = 1;
	while (n < 0)
	{
		if (n / 10 != 0)
			size++;
		n /= 10;
	}
	return (size);
}

static char	*ft_ltoa(long n)
{
	char	*res;
	size_t	size;
	size_t	iter;
	size_t	sign;

	sign = (n < 0);
	iter = 0;
	size = ft_get_digit_size(n);
	res = (char *)ft_calloc(sign + size + 1, sizeof(char));
	if (!res)
		return (0);
	res[0] = '-';
	if (n > 0)
		n *= -1;
	while (iter < size)
	{
		res[sign + size - 1 - iter] = (char)(-(n % 10) + '0');
		n /= 10;
		iter++;
	}
	return (res);
}

static long	ft_atol(const char *str)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	while (ft_strchr("\t\n\v\f\r ", *str) && *str)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (ft_isalnum(*str) && !ft_isalpha(*str) && *str)
	{
		res *= 10;
		res += (long)(*str - '0');
		str++;
	}
	return ((long)(sign * res));
}

int	builtin_exit(int argc, char **argv, char *prompt)
{
	char	*atol_res_str;
	long	atol_res;

	ft_putendl_fd("exit", 2);
	if (argc == 1)
		return (0);
	atol_res = ft_atol(argv[1]);
	atol_res_str = ft_ltoa(atol_res);
	if (ft_strncmp(atol_res_str, argv[1], ft_strlen(argv[1])) == 0)
	{
		if (argc == 2)
			return ((unsigned char)atol_res);
		else
		{
			builtin_perror_manager(prompt, argv[0], argv[1], \
					"too many arguments");
			return (-1);
		}
	}
	else
	{
		builtin_perror_manager(prompt, argv[0], argv[1], \
				"numeric argument required");
		return (255);
	}
}
