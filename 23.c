#include <stdio.h>

int	main(void)
{
	void *a;
	char *value = "123";
	a = value;

	printf("%s\n", (char *)a);
}