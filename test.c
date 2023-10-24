
#include <stdio.h>

typedef struct s_list
{
	int		b;
	char	a;
}	t_list;

int	main(void)
{
	t_list	a;
	t_list	b;

	a.a = 50;
	a.b = 30;
	b.a = 40;
	b.b = 23;
	printf("%d\n",sizeof(a));
	printf("%p\n",b);
}
