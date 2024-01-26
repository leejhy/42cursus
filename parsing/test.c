#include <stdio.h>

typedef struct s_list
{
	int	a;
	int	b;
}	t_list;

void	ft(t_list *list)
{
	list->a = 300;
}

int	main()
{
	t_list	a;

	a.a = 10;
	a.b = 20;
	printf("a %d b %d\n", a.a, a.b);
	ft(&a);
	printf("a %d b %d\n", a.a, a.b);
}