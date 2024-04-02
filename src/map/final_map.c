#include "cub3D.h"

void retrieve_the_final_map(t_map *map_struct, t_config *config) 
{
    int i; 
    int j;
    char **map_final;
    int i_final = 0;

    i = map_struct->end_i - map_struct->i_begin_the_map;
    map_final = ft_calloc((i + 2), sizeof(char*));
    if (map_final == NULL)
    {
        ft_putendl_fd_cub("Error\nMemory allocation failed.\n", 2);
        free_config(config);
        exit(EXIT_FAILURE);
    }
    j = 0;
    while( j <= i)
    {   
        map_final[j] = ft_calloc((map_struct->x + 1), sizeof(char));
        if (map_final[j] == NULL) 
        {
            ft_putendl_fd_cub("Error\nMemory allocation failed.\n", 2);
            free_tab(map_final);
            free_config(config);
            exit(EXIT_FAILURE);
        }
        j++;
    }

    i = map_struct->i_begin_the_map;
    while (i <= map_struct->end_i) 
    {
        j = 0; 
        int j_final = 0; 

        while (map_struct->map[i][j])
        {
            if (map_struct->map[i][j] == ' ')
                map_final[i_final][j_final] = '0';
            else 
                map_final[i_final][j_final] = map_struct->map[i][j];
            j++;
            j_final++;
        }
        i++;
        i_final++;
    }
    free_tab(map_struct->map);
    // map_struct->map = NULL;
    map_struct->map = map_final;
	print_the_map(map_final);

}