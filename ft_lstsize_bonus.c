/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:22:57 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/28 15:11:44 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)//노드가 한 개 밖에 없으면 1나와야 되니까
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
int	main(void)
{
	
}