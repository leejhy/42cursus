/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:49:27 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/26 10:57:12 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}	t_list;

int		ft_makenode(t_list **head, int fd);
void	ft_delnode(t_list **head, int fd);
char	*get_next_line(int fd);
char	*ft_get_oneline(char *read_line);
char	*ft_read_line(int fd, char *buf, char **backup);
int		is_nl(char *str);
char	*ft_strchr(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
int		ft_error(int fd, t_list **head);

#endif
