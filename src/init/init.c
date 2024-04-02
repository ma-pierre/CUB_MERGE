
#include "cub3D.h"
#include "struct.h"

t_map	*init_the_map_struct(char *filename)
{
	t_map	*map_struct;

	map_struct = ft_calloc(1, sizeof(t_map));
	if (!map_struct)
		return (NULL);
	map_struct->map_name = filename;
	return (map_struct);
}

// void init_the_config_struct(t_config *config)
// {
// 	config->north_texture = NULL;
// 	config->south_texture = NULL;
// 	config->west_texture = NULL;
// 	config->east_texture = NULL;
// 	config->floor_color = 0;
// 	config->ceiling_color = 0;
// 	config->flag = 0;
// }
