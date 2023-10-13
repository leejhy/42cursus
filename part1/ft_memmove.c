/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:17:38 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/10 18:55:09 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	i = 1;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst == NULL && temp_src == NULL)
		return (NULL);
	if (temp_dst <= temp_src)
		return(ft_memcpy(temp_dst, temp_src, len));
	else
	{
		while(len - i)
		{
			*(temp_dst + (len - i)) = *(temp_src + (len - i));
			i++;
		}
	}
	return (dst);
}

// int main(void)
// {
//     char str[] = "12345678";
 
//     memmove(str + 2, str, sizeof(char) * 4);
//     printf("src  : %s\n", str);
	
// 	return (0);
// }
