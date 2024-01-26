#include "fdf.h"

int	check_ln(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == 13 || str[i] == '\n' || str[i] == '\0')//str[i] == 13빼기
		return (0);
	return (1);
}

void	check_valid_map(char **map, size_t col_cnt, size_t line_cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < line_cnt)
	{
		if (col_cnt != ft_col_cnt(map[i], " \t"))
			map_error();//map 크기 안맞는거 에러
		while (j < col_cnt)
		{
			if (!(('0' <= map[i][j] && map[i][j] <= '9')
				|| map[i][j] == ' ' || map[i][j] == '\n' || map[i][j] == '\t'
				|| map[i][j] == '+' || map[i][j] == '-'))
				map_error();
			j++;
		}
		i++;
	}
}

int		is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

size_t	ft_col_cnt(char *str, char *sep)
{
	size_t	cnt;

	cnt = 0;
	while (*str != '\0' && *str != '\n')
	{
		while (*str != '\0'&& is_sep(*str, sep))
			str++;
		if (*str != '\0' && *str != '\n')
			cnt++;
		while (*str != '\0' && !is_sep(*str, sep))
			str++;
	}
	return (cnt);
}
