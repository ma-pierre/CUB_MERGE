
#include "cub3D.h"

int	ft_strlen_cub(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_cub(const char *s1) 
{
    size_t	i_cub;
    size_t	i;
    char	*dest;

    i_cub = ft_strlen(s1);
    while (i_cub > 0 && s1[i_cub - 1] == ' ') 
        i_cub--;
    dest = malloc(sizeof(char) * (i_cub + 1));
    if (dest == NULL) 
        return NULL;
    i = 0;
    while (i < i_cub) 
	{
        dest[i] = s1[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/*char	*ft_strdup_cub(const char *s1)
{
	size_t	i_cub;
	size_t	i;
	char	*dest;
	char	*s;

	s = (char *)s1;
	i_cub = ft_strlen(s1);
	while (s[i_cub])
	{
		if(is_whitespace(s[i_cub]))
		{
			i_cub--;
			break;
		}
		i_cub++;
	}
	dest = malloc(sizeof(char) * i_cub + 1);
	i = 0;
	if (dest == NULL)
		return (0);
	else
	{
		while (s[i] && i < i_cub)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}*/

void	actualize_nb_of_col(char *line, int *nb_of_cols)
{
	int	actual_col;

	actual_col = ft_strlen(line) - 1;
	if (actual_col >= *nb_of_cols)
		*nb_of_cols = actual_col;
}

char	*trim_new_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	ft_putendl_fd_cub(char *s, int fd)
{
	if (!s)
		return (EXIT_FAILURE);
	if (write(fd, s, ft_strlen(s)) == -1)
		return (EXIT_FAILURE);
	if (write(fd, "\n", 1) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

int	is_valid_scene_character(char c, t_map *map_struct)
{
	if (c == PLAYER_NORTH || c == PLAYER_SOUTH || is_whitespace(c)
		|| c == PLAYER_EAST || c == PLAYER_WEST)
	{
		if(c == PLAYER_NORTH || c == PLAYER_SOUTH
		|| c == PLAYER_EAST || c == PLAYER_WEST)
		{
			map_struct->flag_pos +=1;
			map_struct->player_start_dir = c;
			return(EXIT_SUCCESS);
		}
		return(EXIT_SUCCESS);
	}
	else if (c == FREE_WAY || c == WALL || c == SPACES || c == '\n')
		return(EXIT_SUCCESS);
	else
		return(EXIT_FAILURE);
}