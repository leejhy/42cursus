/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:32:41 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/19 17:47:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // 

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(char *buf);
char	*ft_freejoin(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_str(char *str, char *headbuf, char *buf, int read_size);
void	ft_fd_lst(t_list **head, int fd);
char	*ft_readline(int fd, char *buf, char **backup)
char	*ft_getoneline(char *str, int *idx);
int		is_lf(char *str);

#endif
