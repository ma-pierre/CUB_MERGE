#include "cub3D.h"

void	free_strs(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_struct(t_map *map_data)
{
	int	i;

	if (map_data)
	{
		if (map_data->map)
		{
			i = 0;
			while (map_data->map[i])
			{
				free(map_data->map[i]);
				//map_data->map[i] = NULL;
				i++;
			}
			free(map_data->map);
		}
		free(map_data);
		map_data = NULL;
	}
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if(tab)
	{
		while (tab[i])
		{
			free(tab[i]);
				i++;
		}
		free(tab);
	}
}

void free_config(t_config *config)
{
    if (!config)
        return;
    if (config->north_texture)
        free(config->north_texture);
    if (config->south_texture)
        free(config->south_texture);
    if (config->west_texture)
        free(config->west_texture);
    if (config->east_texture)
        free(config->east_texture);
    if (config->map_struct) 
	{
        free_map_struct(config->map_struct);
    }
    free(config);
}
