#include <stdio.h>

// int	ft_recursive_factorial(int nb)
// {
// 	if (nb < 0)
// 		return (0);
// 	if (nb == 0 || nb == 1)
// 		return (1);
// 	return (nb * ft_recursive_factorial(nb - 1));
// }

// int	main(void)
// {
// 	for (int i = 0; i <= 10; i++)
// 		printf("%d! = %d\n", i, ft_recursive_factorial(i));
// }

int	add(int a, int b)
{
	return (a+b);
}

int	main(void)
{
	printf("%d\n",add(5,6));
}