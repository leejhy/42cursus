#include <stdio.h>

int	main(void)
{
	size_t	a;
	size_t	b;
	a = -9223372036854775808;
	b = 9223372036854775807;
	size_t	c;
	c = a*b;
	printf("%d\n",c);
}