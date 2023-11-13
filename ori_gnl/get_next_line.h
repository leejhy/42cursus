/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:55:03 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/09 22:00:05 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // 

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1, size_t read_size);
char	*ft_strjoin(char const *s1, char const *s2);
int		is_lf(char *buf);
char	*get_str(char *str, char *buf, int read_size);

#endif
