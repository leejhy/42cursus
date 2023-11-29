/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:37:41 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/29 16:51:49 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>//
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>//va_args

int		ft_printf(const char *str, ...);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long long n, int fd);
void	ft_recursion(long long nb, int fd);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base(long long nb, char *base, int base_len, int *len);
int	ft_puthex(char form_c, unsigned int nb, int *len);
int	ft_formchar(char form_c, int *len, va_list ap);
#endif