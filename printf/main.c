#include "ft_printf.h"

int	main(void)
{
	int a = 214748;
	int b = 31222;
	ft_printf("ft :: %x %dd #%%%X %%d %i %p\n", a, b, a, b, &a);
	printf("%x %dd #%%%X %%d %i %p\n", a, b, a, b, &a);
}
