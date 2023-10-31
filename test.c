#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*newlst;
	t_list	*newnode;
	t_list	*newnode1;

	newlst = NULL;
	lst = (t_list *)malloc(sizeof(t_list));
	newnode = (t_list *)malloc(sizeof(t_list));
	newnode1 = (t_list *)malloc(sizeof(t_list));

	lst->content = "111";
	newnode->content = "222";
	newnode1->content = "333";
	
	lst->next = newnode;
	newnode->next = newnode1;
	newnode1->next = NULL;

	
	while (lst != NULL)
	{
		ft_lstadd_back(&newlst, ft_lstnew(lst->content));
		lst = lst->next;
	}
	while (newlst != NULL)
	{
		printf("%s\n",(char *)newlst->content);
		newlst = newlst->next;
	}
}
