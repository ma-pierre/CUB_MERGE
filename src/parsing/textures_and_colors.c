#include "cub3D.h"

int		ft_result_color(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}


int		rgbstr_to_int(char *line)
{
    int i;

    i = 0;
    if (line && line[i])
    {
        while(line[i] == ' ')
            i++;
        int r = ft_atoi(line + i);
        if (line[i] == '\0')
            return(-1);
        if (r >= 0 && r <= 255)
        {
            while (line[i] && ft_isdigit(line[i]))
                i++;
            if (line[i] && (line[i] == ',' || line[i] == ' '))
            {
                i++;
                while(line[i] == ' ')
                    i++;
                int g = ft_atoi(line + i);
                if (line[i] == '\0')
                    return(-1);
                if (line[i] && g >= 0 && g <= 255)
                {
                    while (line[i] && ft_isdigit(line[i]))
                        i++;
                    if (line[i] && (line[i] == ','))
                    {
                        i++;
                        while(line[i] == ' ')
                            i++;
                        int b = ft_atoi(line + i);
                        // printf("line[i] : %c\n", line[i]);
                        // printf("line : %s\n", line + i);
                        // if( line[i])
                        //     printf("here is a bslashhh\n");
                        if (line[i] == '\0')
                            return(-1);
                        if (line[i] && b >= 0 && b <= 255 && !ft_result_color(line, i))
                            return ((r * 65536) + (g * 256) + b);
                    }
                }
            }
        }
    }
	return (-1);
}
/*
r * 65536 est équivalent à r << 16. Cela revient à décaler la valeur de rouge de 16 bits vers la gauche, ce qui équivaut à la multiplier par 
2
16
2 
16
  ou 
65536
65536.
g * 256 est équivalent à g << 8. Cela revient à décaler la valeur de vert de 8 bits vers la gauche, ce qui équivaut à la multiplier par 
2
8
2 
8
  ou 
256
256.
b reste inchangé car c'est la composante de couleur la moins significative dans l'ordre des bits.
Cette manière d'écrire l'opération donne le même résultat, mais utilise des opérations arithmétiques classiques plutôt que des opérations sur les bits. Cela peut être plus intuitif pour comprendre comment les différentes composantes de couleur sont combinées en une seule valeur entière.*/

void init_floor_color(char *line, t_config *config)
{
    config->floor_color = rgbstr_to_int(line);
    if (config->floor_color == -1)
    {
        free_config(config);
        ft_putendl_fd_cub(INVALID_TEXT_COL, 2);
        exit(EXIT_FAILURE);
    }
}

void init_ceiling_color(char *line, t_config *config)
{
    config->ceiling_color = rgbstr_to_int(line);
    if (config->ceiling_color == -1)
    {
        free_config(config);
        ft_putendl_fd_cub(INVALID_TEXT_COL, 2);
        exit(EXIT_FAILURE);
    }
}

int check_texture_and_color(char *line, t_config *config)
{
    int i;

    i = 0;
    while(*line == ' ')
        line++;
    if (ft_strncmp(line, "NO ", 3) == 0)
    {
        static int f_north = 0;
        if(f_north == 0)
            config->flag += 1;
        f_north = 1;
        line += 2;
        while(*line == ' ')
            line++;
        free(config->north_texture);
        config->north_texture = ft_strdup_cub(line);
        if (config->flag == 6)
			config->map_struct->j_end_of_tc = ft_strlen(line);
    }
    else if (ft_strncmp(line, "SO ", 3) == 0)
    {
        static int f_south = 0;
        if(f_south == 0)
            config->flag += 1;
        f_south = 1;
        line += 2;
        while(*line == ' ')
            line++;
        free(config->south_texture);
        config->south_texture = ft_strdup_cub(line);
        if (config->flag == 6)
			config->map_struct->j_end_of_tc = ft_strlen(line);
    }
    else if (ft_strncmp(line, "WE ", 3) == 0)
    {
        static int f_west = 0;
        if(f_west == 0)
            config->flag += 1;
        f_west = 1;
        line += 2;
        while(*line == ' ')
            line++;
        free(config->west_texture);
        config->west_texture = ft_strdup_cub(line);
        if (config->flag == 6)
			config->map_struct->j_end_of_tc = ft_strlen(line);
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        static int f_east = 0;
        if(f_east == 0)
            config->flag += 1;
        f_east = 1;
        line += 2;
        while(*line == ' ')
            line++;
        if (config->flag == 6)
			config->map_struct->j_end_of_tc = ft_strlen(line);
        free(config->east_texture);
        config->east_texture = ft_strdup_cub(line);
    }
    else if (ft_strncmp(line, "F ", 2) == 0)
    {
        static int f_f = 0;
        if(f_f == 0)
            config->flag += 1;
        f_f = 1;
        line += 2;
        while(*line == ' ')
            line++;
        init_floor_color(line, config);
        if (config->flag == 6)
			config->map_struct->j_end_of_tc = ft_strlen(line);
    }
    else if (ft_strncmp(line, "C ", 2) == 0)
    {
        int f_c = 0;
        if(f_c == 0)
            config->flag += 1;
        f_c = 1;
        line += 2;
        while(*line == ' ')
            line++;
        init_ceiling_color(line, config);
        if (config->flag == 6)
			config->map_struct->j_end_of_tc = ft_strlen(line);
    }
    else if ((*line != '\0') && (*line != '\n') && (config->flag != 6))
        return(0);
    return (1);
}



