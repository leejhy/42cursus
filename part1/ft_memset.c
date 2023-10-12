/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:15:18 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/10 21:49:06 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    size_t          i;
    unsigned char   *temp_b;
	
    temp_b = (unsigned char *)b;
    i = 0;
    while (i < len)
    {
        *(temp_b + i) = (unsigned char)c;
        i++;
    }
    return (b);
}