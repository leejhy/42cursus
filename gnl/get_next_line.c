/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:58:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/07 20:50:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int is_lf(char *buf, int *flag)
{
    int i;
    i = 0;
    while (buf[i])
    {
        if (buf[i] == '\n')
        {
            *flag = 1;
            i++;
            break ;
        }
        i++;
    }
    return (i);
}

char    *get_str(char **str, char *buf, int read_size)
{
    char    *temp;
    // char    *tmp_str; 여기서 tmp_str 받아서 63번 줄에 있는 free를 동작 못하나?

    temp = ft_strdup(buf, read_size);//읽은 크기만큼만 duplicate
    *str = ft_strjoin(*str, temp);
    free(temp);
    return (*str);
}

char    *get_next_line(int fd)
{
    char        *buf;
    static char *str;
    char        *tmp_str;
    size_t      read_size;
    int         flag;

    flag = 0;
    str = NULL;
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while (!flag)
    {
        read_size = read(fd, buf, 1);
        if (read_size == 0)
            break;
        buf[read_size] = '\0';
        read_size = is_lf(buf, &flag);
        tmp_str = str;
        str = get_str(&str, buf, read_size);
        if (tmp_str)
            free(tmp_str);
        printf("%s\n",str);
    }
    free(buf);
    return (str);
}

int main(void)
{
    int     fd;
    char    *str;
    fd = open("text.txt", O_RDONLY);
    //open해서 text.txt의? fd 저장
    str = get_next_line(fd);
    printf("%s", str);
    // fd = open("text1.txt", O_RDONLY);
    // str = get_next_line(fd);
    // printf("%s", str);
    // free(str);
    //str = get_next_line(fd);
    //printf("%s", str);
}