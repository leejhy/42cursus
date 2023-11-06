/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:58:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/05 18:20:31 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE//지울예정
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // O_RDONLY
char    *get_next_line(int fd)
{
    int value_read;
    if (fd < 0)//fd가 음수면 파일 열기 실패
        return (NULL);
    static char *str;
    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    value_read = read(fd, str, BUFFER_SIZE);
	//value_read로 read로 읽는 버퍼 크기 받고 str에 fd에서 읽은 BUFFER_SIZE 받기
    printf("%d\n",value_read);
    return (str);
}
int main(void)
{
    int fd;
    char *str;
    fd = open("text.txt", O_RDONLY);// text읽기
    str = get_next_line(fd);
    printf("%s\n",str);
}
