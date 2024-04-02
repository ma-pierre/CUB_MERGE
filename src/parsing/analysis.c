
#include "cub3D.h"

int	parsing(t_map *map_struct, t_config *config)
{
	if (map_empty(map_struct, config))
		return (EXIT_FAILURE);
	else if (is_map_valid(map_struct, config))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

