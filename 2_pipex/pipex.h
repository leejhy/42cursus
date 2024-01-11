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
# include <sys/wait.h>
# include <fcntl.h>//open

//pipex.c
void	ft_parent(int *pipe_fd, char **argv, char **envp);
void	ft_child_one(int *pipe_fd, int fd_file1, char **cmd1, char *cmd1_path);
void	ft_child_one(int *pipe_fd, int fd_file1, char **cmd1, char *cmd1_path);
//pipex_utils.c
size_t	ft_word_cnt(char *str, char sep);
char	*ft_strdup(char *str, char sep);
char	**ft_split(char *str);
//parsing.c
char	*ft_path_cmd(char *cmd, char **envp);
char	*ft_match_path(char *str_path, char *cmd);
char	*ft_get_path(char **envp);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
//process.c
void	wait_process(int process_cnt);
//error.c
void	ft_error(int err);
void	malloc_failed(void);
#endif