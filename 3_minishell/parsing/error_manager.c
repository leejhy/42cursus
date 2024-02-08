/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/05 16:59:34 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	*parse_error_manager(char *prompt, char *str, int exitcode)
{
	ft_putstr_fd(prompt, 2);
	perror(str);
	if (exitcode != -1)
		exit(exitcode);
	return (NULL);
}

void	*print_error(char *prompt, char *str)
{
	ft_putstr_fd(prompt, 2);
	ft_putstr_fd(str, 2);
	return (NULL);
}
