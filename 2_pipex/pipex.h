/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:39 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/19 17:58:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>

//pipex.c
void	ft_parent(int *pipe_fd, char **argv, char **envp);
void	ft_child_one(char *file, int *pipe_fd, char **cmd1, char **envp);
void	ft_child_two(char *file, int *pipe_fd, char **cmd2, char **envp);
//pipex_utils.c
void	wait_process(int prc_cnt);
pid_t	get_fork_pid(void);
size_t	ft_strlen(char *str);
//ft_split.c
size_t	ft_word_cnt(char *str, char sep);
char	*ft_strdup(char *str, char sep);
void	split_frees(char **ptr);
char	**ft_split(char *str);
//get_path.c
char	**get_cmd(char *cmd, char **envp);
char	*ft_find_path(char *cmd, char **envp);
char	*ft_path_cmd(char *find_path, char *path, char *cmd);
char	*ft_get_path(char **envp);
int		ft_strncmp(char *s1, char *s2, size_t n);
//error.c
void	ft_error(int err);
void	malloc_failed(void);
void	argument_error(void);
void	cmd_error(void);
int		check_cmd(char **cmd);

#endif