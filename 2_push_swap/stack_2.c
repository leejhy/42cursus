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

void	ft_makestackB(t_stack *head_B, t_pos *pos_B, int nb)
{
	t_stack	*newnode;

	newnode = ft_makeNewNode(nb);
}