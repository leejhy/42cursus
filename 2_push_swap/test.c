#include <stdio.h>
typedef struct	s_stack
{
	int				nb;
	struct	s_stack *prev;
	struct	s_stack *next;
}	t_stack;

typedef struct	s_pos
{
	int	size;
	t_stack	*front;
	t_stack	*rear;
}	t_pos;

void	init_varieble(t_stack **head_A, t_stack **head_B, t_pos **pos_A, t_pos **pos_B)
{
	*head_A = NULL;
	*head_B = NULL;
	*pos_A = NULL;
	*pos_B = NULL;

}

int	main(void)
{
	t_stack		*head_A;
	t_stack		*head_B;
	t_pos		*pos_A;
	t_pos		*pos_B;

	// init_varieble(&head_A, &head_B, &pos_A, &pos_B);
	printf("%p %p %p %p\n", head_A, head_B, pos_A, pos_B);
}