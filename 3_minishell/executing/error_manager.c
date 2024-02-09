/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:02:02 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/09 16:31:58 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	*exec_error_manager(char *prompt, char *str, int exitcode)
{
	ft_putstr_fd(prompt, 2);
	if (*str == '\0')
		ft_putstr_fd(": ", 2);
	perror(str);
	if (exitcode >= 0)
		exit(exitcode);
	else
		g_last_exitcode = (unsigned char)(-1 * exitcode);
	return (NULL);
}

void	*custom_error_manager(char *prompt, char *name, char *message, int exitcode)
{
	ft_putstr_fd(prompt, 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ",2);
	ft_putendl_fd(message, 2);
	
	if (exitcode >= 0)
		exit(exitcode);
	else
		g_last_exitcode = (unsigned char)(-1 * exitcode);
	return (NULL);
}
