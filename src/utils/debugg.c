
#include "cub3D.h"

void	print_the_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int ft_strslen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}