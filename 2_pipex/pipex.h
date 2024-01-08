/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:39 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/08 20:00:40 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>//write,read, fork pipe
# include <stdlib.h>//exit
# include <stdio.h>//perror
# include <string.h>//strerror
# include <errno.h>
# include <fcntl.h>//open

//pipex.c

//pipex_utils.c
size_t	ft_strlen(char *str);
//error.c
void	ft_error(int err);

#endif