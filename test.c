#include <stdio.h>

int	main(void)
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	int sum = 0;
	int *p = arr;
	while(i < 10)
	{
		sum = sum + *p++;
		i++;
	}
	printf("%d\n",sum);
}