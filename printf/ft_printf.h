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

# include <stdio.h>//del
# include <stdlib.h>//del
# include <unistd.h>
# include <stdarg.h>//va_args
# include <stdint.h>//del

int		ft_printf(char const *format, ...);
int		ft_checkform(char form_c, int *len, va_list ap);
int		ft_putaddr(void *addr, int *len);
int		ft_putdec(int nb, int *len);
int		ft_puthex(char form_c, unsigned long nb, int *len);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *str, int *len);
int		ft_putchar(char c, int *len);
int		ft_putnbr_base(long long nb, char *base, int base_len, int *len);

#endif
