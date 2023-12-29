
#include "push_swap.h"

void	rotate(t_stack *head, t_pos *pos)
{//first becomes the last one
	t_stack *node;
	int	temp_nb;
	
	if (pos->size == 0)
		return ;
	temp_nb = head->nb;
	node = head->next;
	while (node->next != NULL)
	{
		node->prev->nb = node->nb;
		node = node->next;
	}
	node->prev->nb = node->nb;
	node->nb = temp_nb;
}

void	ra(t_stack **head_A, t_pos **pos_A)
{
	rotate(*head_A, *pos_A);
	printf("ra\n");
}

void	rb(t_stack **head_B, t_pos **pos_B)
{
	rotate(*head_B, *pos_B);
	printf("rb\n");
}

void	rr(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	rotate(*head_A, *pos_A);
	rotate(*head_B, *pos_B);
	printf("rr\n");
}