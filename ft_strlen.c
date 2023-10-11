/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:09:08 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/10 21:35:02 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

size_t ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (*(s + len))
        len++;
    return (len);
}

int main(void)
{
    printf("%d\n",ft_strlen(""));
    printf("%d\n",ft_strlen(""));
    
}