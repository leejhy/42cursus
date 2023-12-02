/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:37:41 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/02 15:23:17 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
int		ft_checkform(char form_c, size_t *len, va_list ap);
int		ft_putaddr(void *addr, size_t *len);
int		ft_puthex(char form_c, unsigned long nb, size_t *len);
int		ft_print_addr(uintptr_t nb, const char *base, size_t *len);
int		ft_putstr(char *str, size_t *len);
int		ft_putchar(char c, size_t *len);
int		ft_putnbr_base(long nb, const char *base, int base_len, size_t *len);
size_t	ft_strlen(const char *s);

#endif
