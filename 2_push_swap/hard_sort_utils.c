
#include "push_swap.h"

int	ft_nbcnt(t_stack *head_A, t_stack *head_B)
{
	t_stack	*temp_A;
	int	cnt;

	cnt = 0;
	temp_A = head_A;
	while (temp_A != NULL && head_B->nb < temp_A->nb)
	{
		cnt += 1;
		temp_A = temp_A->next;
	}
	return (cnt);
}
