#include <stdio.h>
int	main(void)
{
	int a = 53;

	void *ptr = &a;
	printf("%p\n",a);
	printf("%p\n",&a);
	printf("%p\n", ptr);
}