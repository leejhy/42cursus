
#include "push_swap.h"

void	swap(t_stack *head, t_pos *pos)
{
	int	temp_nb;

	if (pos->size <= 1)
		return ;
	temp_nb = head->nb;
	head->nb = head->next->nb;
	head->next->nb = temp_nb;
}

void	sa(t_stack **head_A, t_pos **pos_A)
{
	if ((*pos_A)->size <= 1)
		return ;
	swap(*head_A, *pos_A);
	printf("sa\n");
}

void	sb(t_stack **head_B, t_pos **pos_B)
{
	if ((*pos_B)->size <= 1)
		return ;
	swap(*head_B, *pos_B);
	printf("sa\n");
}

void	ss(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	if ((*pos_A)->size <= 1 || (*pos_B)->size <= 1)
		return ;
	swap(*head_A, *pos_A);
	swap(*head_B, *pos_B);
	printf("ss\n");
}