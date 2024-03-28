#include <iostream>

int	main(int argc, char **argv)
{
	std::string str;
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		str = argv[i];
		while (str[j])
		{
			str[j] = toupper(str[j]);
			j++;
		}
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
	return (0);
}