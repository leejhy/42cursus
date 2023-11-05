#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	if (*lst == NULL)
		*lst = new;
	else
		last_node->next = new;
}

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
	t_list	*newlst;
	char a[5][5] = {"000", "111", "222", "333", "444"};
	// int	val = 0;
	// int *a = &val;
	newlst = NULL;
	int i = 0;
	while (i < 5)
	{
		newnode = ft_lstnew(a[i]);
		// newnode = ft_lstnew(a);
		// (*a)++;
		printf("%d : %p\n", i, newnode);
		ft_lstadd_back(&newlst, newnode);
		i++;
	}
	printf("\n\n");
	i = 0;
	while (newlst != NULL)
	{
		printf("%p\n", newlst);
		printf("content : %s\n\n", newlst->content);
		// printf("content : %d\n", *(int *)(newlst->content));
		newlst = newlst->next;
	}
}