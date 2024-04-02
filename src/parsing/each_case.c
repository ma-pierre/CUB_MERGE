
#include "cub3D.h"

int	map_empty(t_map *map_struct, t_config *config)
{
	(void)config;
	if (map_struct->y == 0 || map_struct->x == 0)
	{
		ft_putendl_fd_cub(ERROR_FILE_EMPTY, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	is_map_border_closed(t_map *map_struct, t_config *config) /*POINTEUR DE FONCTIONS*/
{
	char	**map;

	map = map_struct->map;
	(void)config;

	while(map[map_struct->i_end_of_tc][map_struct->j_end_of_tc])
	{
		if (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc] != '1')
		{
			printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc - 1);
			free_config(config);
			exit(EXIT_FAILURE);
		}
		map_struct->j_end_of_tc++;
	}
	int i = map_struct->i_end_of_tc;
	int j = map_struct->j_end_of_tc;
	while(map[i][j])
	{
		if (map[i][j] != '1')
		{
			printf(MAP_NOT_CLOSED, i, j - 1);
			free_config(config);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	map_struct->i_end_of_tc += 1;
	while(map[map_struct->i_end_of_tc])
	{
		while(map[map_struct->i_end_of_tc][map_struct->j_end_of_tc])
		{
			if(map[map_struct->i_end_of_tc][map_struct->j_end_of_tc] == FREE_WAY
			|| map[map_struct->i_end_of_tc][map_struct->j_end_of_tc] == PLAYER_NORTH
			|| map[map_struct->i_end_of_tc][map_struct->j_end_of_tc] == PLAYER_SOUTH
			|| map[map_struct->i_end_of_tc][map_struct->j_end_of_tc] == PLAYER_EAST
			|| map[map_struct->i_end_of_tc][map_struct->j_end_of_tc] == PLAYER_WEST)
			{
				/*condition pour la derniere ligne*/
				if(map_struct->j_end_of_tc >= ft_strlen_cub(map[map_struct->i_end_of_tc + 1]))
				{
					printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc - 1);
					free_config(config);
					exit(EXIT_FAILURE);
				}
				else if(map_struct->j_end_of_tc == 0)
				{
					printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc - 1);
					free_config(config);
					exit(EXIT_FAILURE);
				}
				else if (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc - 1])
				{
					if((map[map_struct->i_end_of_tc][map_struct->j_end_of_tc - 1] != WALL)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc - 1] != FREE_WAY) 
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc - 1] != PLAYER_NORTH)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc - 1] != PLAYER_SOUTH)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc - 1] != PLAYER_EAST)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc - 1] != PLAYER_WEST))
					{
						printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc - 1);
						free_config(config);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
						printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc - 1);
						free_config(config);
						exit(EXIT_FAILURE);
				}
				if (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc + 1])
				{
					if((map[map_struct->i_end_of_tc][map_struct->j_end_of_tc + 1] != WALL)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc + 1] != FREE_WAY) 
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc + 1] != PLAYER_NORTH)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc + 1] != PLAYER_SOUTH)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc + 1] != PLAYER_EAST)
					&& (map[map_struct->i_end_of_tc][map_struct->j_end_of_tc + 1] != PLAYER_WEST))
					{
						printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc + 1);
						free_config(config);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc + 1);
					free_config(config);
					exit(EXIT_FAILURE);
				}
				if(map[map_struct->i_end_of_tc + 1][map_struct->j_end_of_tc])
				{
					if((map[map_struct->i_end_of_tc + 1][map_struct->j_end_of_tc] != WALL)
					&& (map[map_struct->i_end_of_tc + 1][map_struct->j_end_of_tc] != FREE_WAY) 
					&& (map[map_struct->i_end_of_tc + 1][map_struct->j_end_of_tc] != PLAYER_NORTH)
					&& (map[map_struct->i_end_of_tc + 1][map_struct->j_end_of_tc] != PLAYER_SOUTH)
					&& (map[map_struct->i_end_of_tc + 1][map_struct->j_end_of_tc] != PLAYER_EAST)
					&& (map[map_struct->i_end_of_tc + 1][map_struct->j_end_of_tc] != PLAYER_WEST))
					{
						printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc + 1, map_struct->j_end_of_tc);
						free_config(config);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc, map_struct->j_end_of_tc + 1);
					free_config(config);
					exit(EXIT_FAILURE);
				}
				if(map[map_struct->i_end_of_tc - 1][map_struct->j_end_of_tc + 1])
				{
					if((map[map_struct->i_end_of_tc - 1][map_struct->j_end_of_tc] != WALL)
					&& (map[map_struct->i_end_of_tc - 1][map_struct->j_end_of_tc] != FREE_WAY) 
					&& (map[map_struct->i_end_of_tc - 1][map_struct->j_end_of_tc] != PLAYER_NORTH)
					&& (map[map_struct->i_end_of_tc - 1][map_struct->j_end_of_tc] != PLAYER_SOUTH)
					&& (map[map_struct->i_end_of_tc - 1][map_struct->j_end_of_tc] != PLAYER_EAST)
					&& (map[map_struct->i_end_of_tc - 1][map_struct->j_end_of_tc] != PLAYER_WEST))
					{
						printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc - 1, map_struct->j_end_of_tc);
						free_config(config);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf(MAP_NOT_CLOSED, map_struct->i_end_of_tc - 1, map_struct->j_end_of_tc);
					free_config(config);
					exit(EXIT_FAILURE);
				}
			}
			map_struct->j_end_of_tc++;
		}
		map_struct->j_end_of_tc = 0;
		map_struct->i_end_of_tc++;
	}
	return (EXIT_SUCCESS);
}

int	is_map_valid(t_map *map_struct, t_config *config)
{
	char	**map;
	int		i;
	int		j;

	map = map_struct->map;
	j = 0;
	i = 0;
	while (map[i])
	{
		if (!check_texture_and_color(map[i], config))
		{
			ft_putendl_fd_cub(INVALID_TEXT_COL, 2);
			free_config(config);
			exit(EXIT_FAILURE);
		}
		if (config->flag == 6)
			break;
		else
			i++;
	}
	if (config->flag != 6)
	{
		ft_putendl_fd_cub(INVALID_TEXT_COL, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	if (check_if_xpm(config->north_texture) || check_if_xpm(config->south_texture) 
	|| check_if_xpm(config->east_texture) || check_if_xpm(config->west_texture))
	{

		ft_putendl_fd_cub(INV_EXT_XPM, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	if (open_for_the_xpm(config->north_texture) || open_for_the_xpm(config->south_texture) 
	|| open_for_the_xpm(config->east_texture) || open_for_the_xpm(config->west_texture))
	{
		ft_putendl_fd_cub(INV_XPM_FILE_NOT_FOUND, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	map_struct->i_end_of_tc = i + 1; //checker la fin de la ligne[i]
	map_struct->i_begin_the_map = map_struct->i_end_of_tc;
	while (map[map_struct->i_begin_the_map])
	{
		j = 0;
		while (map[map_struct->i_begin_the_map][j] == ' ' 
		&& map[map_struct->i_begin_the_map][j] == '\0'
		&& map[map_struct->i_begin_the_map][j] == '\n')
			j++;
		if (map[map_struct->i_begin_the_map][j] != '\0' 
		&& map[map_struct->i_begin_the_map][j] != '\n'
		&& map[map_struct->i_begin_the_map][j] != ' ')
			break;
		map_struct->i_begin_the_map++;
	}
	if(!map[map_struct->i_begin_the_map])
	{
		ft_putendl_fd_cub(ERROR_MAP_EMPTY, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while(map[map_struct->i_end_of_tc])
	{
		while(map[map_struct->i_end_of_tc][j] == ' ')
			j++;
		if ((map[map_struct->i_end_of_tc][j] !='\0') && (map[map_struct->i_end_of_tc][j] !='\n'))
			break;
		map_struct->i_end_of_tc++;
	}
	map_struct->j_end_of_tc = j;
	while (map[i + 1])
	{
		j = 0;
		while (map[i + 1][j])
		{
			if (is_valid_scene_character(map[i + 1][j], map_struct))
			{
				printf(INVALID_CHAR_MSG, i, j);
				free_config(config);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	if (map_struct->flag_pos != 1)
	{
		ft_putendl_fd_cub(INVALID_POSITION, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	if (is_map_border_closed(map_struct, config))
	{
		free_config(config);
		exit(EXIT_FAILURE);
	}
	print_the_map(map);
	printf("\n\n parsing versus exec\n\n");
	if(under_the_map(config) == 1)
	{
		free_config(config);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_config 	*config;
	t_data		data;

	config = ft_calloc(1, sizeof(t_config));
	if (!config)
		return (EXIT_FAILURE);
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments.");
		return (EXIT_FAILURE);
	}
	config->map_struct = init_the_map_struct(argv[1]);
	if (!config->map_struct)
	{
		ft_putendl_fd_cub(FAIL_INIT_STRUCT, 2);
		return (EXIT_FAILURE);
	}
	if (check_if_dotcub(argv[1]))
	{
		ft_putendl_fd_cub(INV_EXT, 2);
		free_config(config);
		return (EXIT_FAILURE);
	}
	if (count_and_read(config->map_struct))
	{
		free_config(config);
		return (EXIT_FAILURE);
	}
	if (parsing(config->map_struct, config))
	{
		free_config(config);
		return (EXIT_FAILURE);
	}
	retrieve_the_final_map(config->map_struct, config);
	////////////////////////////////////////////////////////////////
	data.player_start_dir = config->map_struct->player_start_dir;
	printf("PLAYERDIR = %c \n", data.player_start_dir);
	data.WorldMap = config->map_struct->map;
	int i = 0;
	int j;
	while(data.WorldMap[i])
	{
			j = 0;
		while(data.WorldMap[i][j])
		{ 
			if (data.WorldMap[i][j] == data.player_start_dir)
			{
				data.posX = (double)j ;
				data.posY = (double)i ;
				data.WorldMap[i][j] = 0;
				printf(" i = %d j = %d \n", i , j);
			}
			j++;
		}
		i++;
	}
	printf("pos X : %f\n", data.posX);
	printf("pos Y : %f\n", data.posY);	
	//print_the_map(data.WorldMap);
	printf("ici c bon\n");
	/////////////////////////////////////////////////////////////////////
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		printf("pk tu veux casser mon cuuuuuuuub");
		return (1);
	}
	init_player_direction(&data);
	data.moveSpeed = 0.01;
	data.rotSpeed = 0.01;
	
	init_keys(&data);
	data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, "eya et marine");
	//init_minimap(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_loop_hook(data.mlx, &do_frame, &data);
	mlx_loop(data.mlx);
	//close(config->map_struct->fd);
	//free_config(config);		
}
