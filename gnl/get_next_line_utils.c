/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:40:09 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/07 20:28:08 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//helper functions
size_t  ft_strlen(const char *s)
{
    size_t  len;
    len = 0;
    while (s && *(s + len))
        len++;
    return (len);
}

char    *ft_strdup(const char *s1, size_t read_size)
{
    char    *arr;
    size_t  i;
    size_t  s1_len;
    i = 0;
    arr = (char *)malloc(sizeof(char) * (read_size + 1));
    if (!arr)
        return (NULL);
    while (i < read_size)
    {
        *(arr + i) = *(s1 + i);
        i++;
    }
    *(arr + i) = '\0';
    return (arr);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  s1_len;
    size_t  s2_len;
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    str = malloc(sizeof (char) * (s1_len + s2_len + 1));
    if (!str)
        return (NULL);
    while (s1 && *s1)
        *str++ = *s1++;
    while (s2 && *s2)
        *str++ = *s2++;
    *str = '\0';
    return (str - (s1_len + s2_len));
}
