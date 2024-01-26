/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:32:41 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/18 21:01:55 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 100

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
char	*ft_gnldup(const char *s1);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
int		gnl_error(int fd, t_list **head);

#endif
