/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:45:07 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/31 19:26:04 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
#include <stdio.h>

int	main(void)
{
	t_list	*newnode;
	void	*a;
	a = (char *)"123";
	int i = 0;
	while (i < 5)
	{
		newnode = ft_lstnew(a);
		printf("%p\n",newnode);
		i++;
	}
}