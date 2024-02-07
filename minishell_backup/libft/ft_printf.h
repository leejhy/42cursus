/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/12/29 20:38:37 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define FALSE 0
# define TRUE 1

typedef struct s_save_print {
	char	*str;
	int		size;
	int		len;
}	t_save_print;

void				pf_flag_c(t_save_print *res, va_list argptr);
void				pf_flag_s(t_save_print *res, va_list argptr);
void				pf_flag_p(t_save_print *res, va_list argptr);
void				pf_flag_d(t_save_print *res, va_list argptr);
void				pf_flag_i(t_save_print *res, va_list argptr);
void				pf_flag_u(t_save_print *res, va_list argptr);
void				pf_flag_x(t_save_print *res, va_list argptr);
void				pf_flag_xx(t_save_print *res, va_list argptr);
void				pf_flag_perc(t_save_print *res);
char				*pf_error_manager(t_save_print *res, int flag);

char				*pf_get_hex(unsigned long p, int flag, int is_xx);
int					pf_get_px_size(unsigned long px);
char				*pf_transfer(char *tmp, t_save_print *res);
char				*ft_itoa_unsigned_int(long n);
int					pf_get_digit_size(long n);

t_save_print		*pf_res_init(void);
char				*pf_resize_str(t_save_print *res);
const char			*pf_put_convention(const char *str, \
					t_save_print *res, va_list argptr);
const char			*pf_not_convention(const char *str, t_save_print *res);
int					ft_printf(const char *str, ...);
#endif
