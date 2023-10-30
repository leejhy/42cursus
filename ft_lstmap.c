#include <stdio.h>
#include "libft.h"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

static int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

static int	insert_node(t_list **head, void *content)
{
	t_list	*nextnode;

	nextnode = (t_list *)malloc(sizeof(t_list));
	if (!nextnode)
		return (0);
	nextnode->content = content;
	nextnode->next = NULL;
	if ((*head)->next == NULL)
	{
		(*head)->next = nextnode;
		return (1);
	}
	else
	{
		(*head) = (*head)->next;
		(*head) = nextnode;
		return (1);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tail;
	size_t	lst_size;
	size_t	i;//iter
	int		nulltester;

	i = 0;
	lst_size = ft_lstsize(lst);
	// tail = ft_lstlast(lst);
	tail = lst;
	newlst = (t_list *)malloc(sizeof(t_list));//head of newlst
	newlst->next = NULL;//NULL init : head
	if (!newlst)
		return (NULL);
	while (i < lst_size)
	{
		nulltester = insert_node(newlst, (*f)(lst->content));
		if (!nulltester)
			return (NULL);
		(*del)(tail->content);
		tail = tail->next;
		i++;
	}
}
	