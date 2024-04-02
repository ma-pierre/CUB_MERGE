#include "cub3D.h"

int    under_the_map(t_config *config)
{
    char    **map;
    int     j;
    char    c;

    j = 0;
    c = 'a';
    map = config->map_struct->map;
    config->map_struct->beg_index = config->map_struct->i_begin_the_map + 1;
    while(map[config->map_struct->beg_index + 1])
    {
        j = 0;
        while(map[config->map_struct->beg_index + 1][j])
        {
            if ((map[config->map_struct->beg_index + 1][j] == '\n' 
            || map[config->map_struct->beg_index + 1][j] == '\0')
            && c == '\n')
                config->map_struct->j_end_of_map = j;
            c = map[config->map_struct->beg_index + 1][j];
            j++;
        }
        if(config->map_struct->j_end_of_map == j)
            break;
        config->map_struct->beg_index++;
    }
    config->map_struct->end_i = config->map_struct->beg_index;
    config->map_struct->end_j = config->map_struct->j_end_of_map;
    // (map[config->map_struct->beg_index + 1][config->map_struct->end_i]);
    while(map[config->map_struct->beg_index + 1])
    {
        j = 0;
        while(map[config->map_struct->beg_index + 1][j] != '\0')
        {
            if(map[config->map_struct->beg_index + 1][j] != SPACES)
            {
                printf(INV_UNDER_THE_MAP);
                free_config(config);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        config->map_struct->beg_index++;
    }
    return(0);
}