/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/29 20:36:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flag_c(t_save_print *res, va_list argptr)
{
	int		c;

	c = va_arg(argptr, int);
	if (res->size - res->len < 1)
		res->str = pf_resize_str(res);
	if (res->str == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	res->str[res->len] = (char)c;
	res->len++;
	return ;
}

void	pf_flag_s(t_save_print *res, va_list argptr)
{
	char	*tmp;

	tmp = va_arg(argptr, char *);
	if (tmp != NULL)
	{
		pf_transfer(tmp, res);
		return ;
	}
	tmp = ft_calloc(7, sizeof(char));
	if (tmp == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	ft_memmove(tmp, "(null)", 6);
	pf_transfer(tmp, res);
	free(tmp);
	return ;
}

void	pf_flag_p(t_save_print *res, va_list argptr)
{
	char			*tmp;
	unsigned long	p;

	p = va_arg(argptr, unsigned long);
	tmp = pf_get_hex(p, 2, 0);
	if (tmp == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	pf_transfer(tmp, res);
	free(tmp);
	return ;
}

void	pf_flag_d(t_save_print *res, va_list argptr)
{
	char	*tmp;
	int		d;

	d = va_arg(argptr, int);
	tmp = ft_itoa(d);
	if (tmp == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	pf_transfer(tmp, res);
	free(tmp);
	return ;
}

void	pf_flag_i(t_save_print *res, va_list argptr)
{
	char	*tmp;
	int		i;

	i = va_arg(argptr, int);
	tmp = ft_itoa(i);
	if (tmp == NULL)
	{
		pf_error_manager(res, 0);
		return ;
	}
	pf_transfer(tmp, res);
	free(tmp);
	return ;
}
