/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/29 20:54:58 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_save_print	*pf_res_init(void)
{
	t_save_print	*res;

	res = ft_calloc(1, sizeof(t_save_print));
	if (res == NULL)
		return (NULL);
	res->str = ft_calloc(2, sizeof(char));
	if (res->str == NULL)
	{
		free(res);
		return (NULL);
	}
	res->size = 1;
	res->len = 0;
	return (res);
}

char	*pf_resize_str(t_save_print *res)
{
	int		extends_size;
	int		idx;
	char	*tmp;

	if (res->str == NULL)
		return (NULL);
	extends_size = res->size * 2;
	tmp = ft_calloc(extends_size + 1, sizeof(char));
	if (tmp == NULL)
		return (pf_error_manager(res, 0));
	idx = 0;
	while (idx < res->len)
	{
		tmp[idx] = res->str[idx];
		idx++;
	}
	free(res->str);
	res->size = extends_size;
	return (tmp);
}

const char	*pf_put_convention(const char *str, \
				t_save_print *res, va_list argptr)
{
	char const	flags[10] = "cspdiuxX%\0";

	if (*str == '\0')
		return (str);
	if (str == NULL || str[1] == '\0' || ft_strchr(flags, str[1]) == NULL)
		return (pf_error_manager(res, 0));
	if (str[1] == 'c')
		pf_flag_c(res, argptr);
	else if (str[1] == 's')
		pf_flag_s(res, argptr);
	else if (str[1] == 'p')
		pf_flag_p(res, argptr);
	else if (str[1] == 'd' || str[1] == 'i')
		pf_flag_d(res, argptr);
	else if (str[1] == 'u')
		pf_flag_u(res, argptr);
	else if (str[1] == 'x')
		pf_flag_x(res, argptr);
	else if (str[1] == 'X')
		pf_flag_xx(res, argptr);
	else if (str[1] == '%')
		pf_flag_perc(res);
	if (res->str == NULL)
		return (NULL);
	return (&(str[2]));
}

const char	*pf_not_convention(const char *str, t_save_print *res)
{
	int	idx;
	int	len;

	len = 0;
	while (str[len] != '%' && str[len] != '\0')
		len++;
	while (res->str != NULL && res->size - res->len < len)
	{
		res->str = pf_resize_str(res);
		if (res->str == NULL)
			return (NULL);
	}
	if (res->str == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		res->str[res->len + idx] = str[idx];
		idx++;
	}
	res->len += idx;
	return (&(str[idx]));
}

int	ft_printf(const char *str, ...)
{
	t_save_print	*res;
	va_list			argptr;
	int				tmp;

	res = pf_res_init();
	if (res == NULL)
		return (-1);
	va_start(argptr, str);
	while (*str != '\0')
	{
		str = pf_not_convention(str, res);
		if (str == NULL)
			return ((int)pf_error_manager(res, 1) - 1);
		str = pf_put_convention(str, res, argptr);
		if (str == NULL)
			return ((int)pf_error_manager(res, 1) - 1);
	}
	va_end(argptr);
	tmp = write(1, res->str, res->len);
	free(res->str);
	free(res);
	return (tmp);
}
