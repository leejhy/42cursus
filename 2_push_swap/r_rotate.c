
#include "push_swap.h"

void	r_rotate(t_stack *head, t_pos *pos)
{//The last elements becomes the first one
	t_stack	*node;
	int	temp_nb;
	
	if (head == NULL)
		return ;
	temp_nb = pos->rear->nb;
	node = pos->rear->prev;
	while (node->prev != NULL)
	{
		node->next->nb = node->nb;
		node = node->prev;
	}
	node->next->nb = node->nb;
	node->nb = temp_nb;
}

void	rra(t_stack **head_A, t_pos **pos_A)
{
	r_rotate(*head_A, *pos_A);
	printf("rra\n");
}

void	rb(t_stack **head_B, t_pos **pos_B)
{
	r_rotate(*head_B, *pos_B);
	printf("rrb\n");
}

void rrr(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	r_rotate(*head_A, *pos_A);
	r_rotate(*head_B, *pos_B);
	printf("rrr\n");
}