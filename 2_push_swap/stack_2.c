#include "push_swap.h"

int	ft_lstsize(t_stack *head)
{
	t_stack	*node;
	int		cnt;

	node = head;
	cnt = 0;
	while (node != NULL)
	{
		cnt += 1;
		node = node->next;
	}
	return (cnt);
}