/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:15 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/31 21:57:24 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, ((char *)elem->content), len);
	write(1, "\n", 1);
}

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}

void	*ft_map(void *ct)
{
	int		i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}


void    ft_del(void *content)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*del_lst;

	del_lst = lst;
	newlst = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		ft_lstadd_back(&newlst, ft_lstnew((*f)(lst->content)));
		(*del)(del_lst->content);
		lst = lst->next;
		free(del_lst);
		del_lst = lst;
	}
	return (newlst);
}
int	main(void)
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*list;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (1)
	{
		if (!(list = ft_lstmap(elem, &ft_map, &ft_del)))
			return (0);
		if (list == elem)
			write(1, "A new list is not returned\n", 27);
		int	i;
		i = 0;
		ft_print_result(list);
		while (list->next)
		{
			list = list->next;
			ft_print_result(list);
			i++;
		}
	}
	return (0);
}
