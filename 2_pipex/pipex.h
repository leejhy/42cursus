/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:39 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/09 17:58:11 by junhylee         ###   ########.fr       */
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
void	ft_parent(pid_t child_one, int *pipe_fd, char **argv, char **envp);
void	ft_child_one(int *pipe_fd, int fd_file1, char **cmd1, char **envp);
void	ft_child_two(int *pipe_fd, int fd_file2, char **cmd2, char **envp);
//pipex_utils.c
size_t	ft_word_cnt(char *str, char sep);
char	*ft_strdup(char *str, char sep);
char	**ft_split(char *str);
//error.c
void	ft_error(int err);
void	malloc_failed(void);
#endif