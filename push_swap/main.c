
#include "push_swap.h"


long long	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

int	is_errors(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	return (0);
}


int	main(int argc, char **argv)
{
	size_t		i;
	long long	nb;
	t_stack		*stack_A;

	i = argc - 1;
	stack_A = malloc(sizeof(t_stack));
	stack_A = NULL;
	if (is_errors)
	{
		printf("Error\n");
		return (0);
	}
	while (i)
	{
		nb = ft_atoi(argv[i]);
		if (!(INT_MIN <= nb && nb <= INT_MAX))
			return (0);
		pa(stack_A, nb);
		i--;
	}
	return (0);
}