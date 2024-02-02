/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 03:22:58 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 15:43:41 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*f_content;
	t_list	*res;
	t_list	*f_new_elem;
	t_list	*here_elem;

	res = NULL;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		here_elem = lst;
		f_content = f(here_elem->content);
		f_new_elem = ft_lstnew(f_content);
		if (!f_new_elem)
		{
			del(f_content);
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, f_new_elem);
		lst = lst->next;
	}
	return (res);
}
