
#include <stdio.h>
#include <stdlib.h>

void	f(int *ptr)
{
	*ptr = 10;
}
int	main(void)
{
	int	a;
	f(&a);
	printf("%d\n", a);
}
