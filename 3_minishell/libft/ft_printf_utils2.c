/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/29 20:36:17 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flag_u(t_save_print *res, va_list argptr)
{
	char			*tmp;
	unsigned int	u;

	u = va_arg(argptr, unsigned int);
	tmp = ft_itoa_unsigned_int(u);
	if (tmp == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	pf_transfer(tmp, res);
	free(tmp);
	return ;
}

void	pf_flag_x(t_save_print *res, va_list argptr)
{
	char			*tmp;
	unsigned int	x;

	x = va_arg(argptr, unsigned int);
	tmp = pf_get_hex((unsigned long)x, 0, 0);
	if (tmp == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	pf_transfer(tmp, res);
	free(tmp);
	return ;
}

void	pf_flag_xx(t_save_print *res, va_list argptr)
{
	char			*tmp;
	unsigned int	xx;

	xx = va_arg(argptr, unsigned int);
	tmp = pf_get_hex((unsigned long)xx, 0, 1);
	if (tmp == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	pf_transfer(tmp, res);
	free(tmp);
	return ;
}

void	pf_flag_perc(t_save_print *res)
{
	if (res->size - res->len < 1)
		res->str = pf_resize_str(res);
	if (res->str == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	res->str[res->len] = '%';
	res->len++;
	return ;
}

char	*pf_error_manager(t_save_print *res, int flag)
{
	if (flag == 0)
	{
		free(res->str);
		res->str = NULL;
		return (NULL);
	}
	else
	{
		free(res);
		res = NULL;
		return (NULL);
	}
}
