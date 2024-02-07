/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/29 20:36:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_get_hex(unsigned long p, int flag, int is_xx)
{
	char			*tmp;
	int				idx;
	int				size;

	size = pf_get_px_size(p);
	tmp = ft_calloc(size + flag + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '0';
	if (size + flag > 1)
		tmp[1] = 'x';
	idx = size + flag - 1;
	while (idx >= flag)
	{
		tmp[idx] = "0123456789abcdef"[p % 16];
		if (is_xx)
			tmp[idx] = "0123456789ABCDEF"[p % 16];
		p /= 16;
		idx--;
	}
	return (tmp);
}

int	pf_get_px_size(unsigned long px)
{
	int	size;

	size = 1;
	while ((px / 16) > 0)
	{
		px /= 16;
		size++;
	}
	return (size);
}

char	*pf_transfer(char *tmp, t_save_print *res)
{
	int		tmp_size;
	int		idx;

	tmp_size = ft_strlen(tmp);
	while (res->size - res->len < tmp_size)
	{
		res->str = pf_resize_str(res);
		if (res->str == NULL)
			return (NULL);
	}
	idx = 0;
	while (tmp[idx])
	{
		res->str[res->len + idx] = tmp[idx];
		idx++;
	}
	res->len += idx;
	return (NULL);
}

char	*ft_itoa_unsigned_int(long n)
{
	char	*res;
	size_t	size;
	size_t	iter;
	size_t	sign;

	sign = (n < 0);
	iter = 0;
	size = pf_get_digit_size(n);
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

int	pf_get_digit_size(long n)
{
	int	size;

	size = 1;
	while ((n / 10) > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
