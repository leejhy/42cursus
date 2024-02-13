/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:02:02 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 15:02:21 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	malloc_failed(void)
{
	ft_putendl_fd("malloc failed", 2);
	exit(1);
}

void	*exec_error_manager(char *prompt, char *str, int exitcode)
{
	ft_putstr_fd(prompt, 2);
	if (!str || *str == '\0')
		ft_putstr_fd(": ", 2);
	perror(str);
	if (exitcode >= 0)
		exit(exitcode);
	else
		g_last_exitcode = (unsigned char)(-1 * exitcode);
	return (NULL);
}

void	*custom_error_manager(char *prompt, char *name, \
							char *message, int exitcode)
{
	ft_putstr_fd(prompt, 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(message, 2);
	if (exitcode >= 0)
		exit(exitcode);
	else
		g_last_exitcode = (unsigned char)(-1 * exitcode);
	return (NULL);
}
