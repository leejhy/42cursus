/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:39 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/15 21:33:26 by junhylee         ###   ########.fr       */
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
void	first_prc(char *file, int *pipe_fd, char **cmd, char **envp);
void	last_prc(int argc, char **argv, int *pipe_fd, char **envp);
void	mid_prc(int *in_pipe, int *out_pipe, char **cmd, char **envp);
void	make_mid_prc(int prc_cnt, int **pipe_fd, char **argv, char **envp);
//init.c
int		**init_pipe(int argc, int *prc_cnt);
void	pipes_free(int **pipes, int free_cnt);
//pipex_utils.c
void	wait_process(int prc_cnt);
pid_t	get_fork_pid(void);
size_t	ft_strlen(char *str);
//ft_split.c
size_t	ft_word_cnt(char *str, char sep);
char	*ft_strdup(char *str, char sep);
void	split_frees(char **ptr);
char	**ft_split(char *str, char **envp);
//get_path.c
char	*ft_find_path(char *cmd, char **envp);
char	*ft_path_cmd(char *find_path, char *path, char *cmd);
char	*ft_get_path(char **envp);
int		ft_strncmp(char *s1, char *s2, size_t n);
//error.c
void	ft_error(int err);
void	malloc_failed(void);
void	argument_error(void);
void	input_error(void);

#endif