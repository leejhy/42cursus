/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:35:57 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/17 22:12:13 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	write(fd, s, s_len);
	write(1, "\n", 1);
}
//  ft_putendl_fd("lorem ipsum dolor sit amet", 2);
// Expected (cat -e test01.output):
// lorem ipsum dolor sit amet$

// Your result (cat -e user_output_test01):
// lorem ipsum dolor sit amet
// Test 3:
//     ft_putendl_fd("", 2);
// Expected (cat -e test03.output):
// $

// Your result (cat -e user_output_test03):
