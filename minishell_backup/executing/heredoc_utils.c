
#include "executing.h"

char	*expanse_input(t_list *env, char *input)
{
	int		size;
	char	*exp_input;

	size = 0;
	expansion_size(input, env, &size);
	exp_input = ft_calloc(size + 1, sizeof(char));
	if (exp_input == NULL)
		return (FALSE);
	expansion_simplecmd(input, exp_input, size, env);
	return (exp_input);
}