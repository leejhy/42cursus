# include <stdlib.h>
# include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct	s_stack
{
	int		nb;
	struct	s_stack *prev;
	struct	s_stack *next;
}	t_stack;