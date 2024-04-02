
#include "cub3D.h"

int	count_and_read(t_map *map_struct)
{
	if (nb_lines_and_col(map_struct))
		return (EXIT_FAILURE);
	if (!read_file_lines(map_struct))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
