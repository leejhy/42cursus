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
char    *get_next_line(int fd)
{
    char        *buf;
    char        *str;
    char        *temp;
    char        *temp1;
    size_t      read_size;
    size_t      i;
    int         flag = 0;
    str = NULL;
    buf = malloc(BUFFER_SIZE + 1);
    while (!flag)
    {
        i = 0;
        read_size = read(fd, buf, 1);
        if (read_size == 0)
            break;
        buf[read_size] = '\0';
        while (buf[i])
        {
            if (buf[i] == '\n')
            {
                flag = 1;
                i++;
                break;
            }
            i++;
        }
        read_size = i;
        temp = ft_strdup(buf, read_size);//읽은 크기만큼만 duplicate
        temp1 = str;
        str = ft_strjoin(str, temp);
        if (temp1)
            free(temp1);
        free(temp);
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
    free(str);
    // fd = open("text1.txt", O_RDONLY);
    // str = get_next_line(fd);
    // printf("%s", str);
    // free(str);
    //str = get_next_line(fd);
    //printf("%s", str);
}