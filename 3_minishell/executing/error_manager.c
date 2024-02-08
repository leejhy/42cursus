/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:02:02 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/07 19:36:04 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	*exec_error_manager(char *prompt, char *str, int exitcode)
{
	ft_putstr_fd(prompt, 2);
	perror(str);
	if (exitcode >= 0)
		exit(exitcode);
	else
		g_last_exitcode = (unsigned char)(-1 * exitcode);
	return (NULL);
}
