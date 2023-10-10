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

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;
	size_t	i;
	i = 0;

	if (dst == NULL && src == NULL)
		return (NULL);

	while (i < len)
	{
		*(temp + i) = *(char *)(src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(char *)(dst + i) = *(temp + i);
		i++;
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
