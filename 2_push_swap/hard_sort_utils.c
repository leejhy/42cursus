
#include "push_swap.h"

int	ft_nbcnt(t_stack *head_A, t_stack *head_B)
{
	t_stack	*temp_A;
	int	cnt;

	cnt = 0;
	temp_A = head_A;
	while (temp_A != NULL)
	{
		if (head_B->nb < temp_A->nb)
			cnt += 1;
		temp_A = temp_A->next;
	}
	return (cnt);
}

int find_zero(t_stack *head_A)
{
	int		loc;
	t_stack *temp_A;

	temp_A = head_A;
	loc = 0;
	while (temp_A != NULL && temp_A->nb != 0)
	{
		loc += 1;
		temp_A = temp_A->next;
	}
	if (temp_A->nb == 0)
		return (loc);
	return (-1);
}

int find_one(t_stack *head_A)
{
	int		loc;
	t_stack *temp_A;

	temp_A = head_A;
	loc = 0;
	while (temp_A != NULL && temp_A->nb != 1)
	{
		loc += 1;
		temp_A = temp_A->next;
	}
	if (temp_A->nb == 1)
		return (loc);
	return (-1);
}

void	ft_select_pb(t_stack **head_A, t_pos **pos_A, t_stack **head_B, t_pos **pos_B)
{
	int loc_one;
	int	loc_zero;

	while (find_zero(*head_A) >= 0 || find_one(*head_A) >= 0)
	{
		loc_zero = find_zero(*head_A);
		loc_one = find_one(*head_A);
		printf("select_pb\n");
		if (loc_one == 0 || loc_zero == 0)
			pb(head_A, pos_A, head_B, pos_B);
		else if (loc_one == 1 || loc_zero == 1)
			ra(head_A, pos_A);
		else if (loc_one == (*pos_A)->rear->nb || loc_zero == (*pos_A)->rear->nb)
			rra(head_A, pos_A);
		else if (loc_one == 2 || loc_zero == 2)
		{
			ra(head_A, pos_A);
			ra(head_A, pos_A);
		}
		else if (loc_one == 3 || loc_zero == 3)
		{
			rra(head_A, pos_A);
			rra(head_A, pos_A);
		}
	}
}

int	is_sorted(t_stack **head_A)
{
	t_stack *temp;
	int		cnt;
	int		size;
	
	cnt = 0;
	size = 0;
	temp = *head_A;
	while (temp->next != NULL)
	{
		if (temp->nb < temp->next->nb)
			cnt += 1;
		size += 1;
		temp = temp->next;
	}
	if (cnt == size)
		return (1);
	return (0);
}