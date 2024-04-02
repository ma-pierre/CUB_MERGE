
#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../mlx/mlx.h"
#include "struct.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define KeyPressMask			(1L<<0)
#define KeyReleaseMask			(1L<<1)
#define KeyPress	2
#define KeyRelease 3
#define screenWidth 640
#define screenHeight 480

/*Errors and success messages*/
# define ERROR_ARGS "Error\nInvalid arguments."
# define INV_FILE_NOT_FOUND "Error\nFile not found."
# define INV_XPM_FILE_NOT_FOUND "Error\nXPM file not found."
# define INV_EXT "Error\nWrong extension's name."
# define INV_EXT_XPM "Error\nWrong extension's name(xpm)."
# define INVALID_POSITION "Error\nProblem with the player's position."
# define INVALID_EXIT "Error\nProblem with the exit."
# define INVALID_TEXT_COL "Error\nProblem with your textures or colors."
# define INV_UNDER_THE_MAP "Error\nSomething letf under the map."
# define MAP_NOT_CLOSED "Error\nMap border not closed here : [%d][%d]. \n"
//#define INV_DIRECTORY "Error: .cub is a directory."
# define ERROR_FILE_EMPTY "Error\nThe file is empty."
# define ERROR_MAP_EMPTY "Error\nThe map is empty."
# define INVALID_CHAR_MSG "Error\nInvalid character : at position [%d][%d]"
# define FAIL_INIT_STRUCT "Error\nInitialisation of the structure failed."

// Enumération pour les caractères de scène
enum		e_scene_characters
{
	FREE_WAY = '0',
	WALL = '1',
	PLAYER_NORTH = 'N',
	PLAYER_SOUTH = 'S',
	PLAYER_EAST = 'E',
	PLAYER_WEST = 'W',
	SPACES = ' '
};

/* Collect the map*/
t_map		*init_the_map_struct(char *filename);
int			nb_lines_and_col(t_map *map_struct);
char		**read_file_lines(t_map *map_struct);
void		retrieve_the_final_map(t_map *map_struct, t_config *config);

// Assignation
// int			cub3D_input(int argc, char **argv);
int			count_and_read(t_map *map_struct);

// Parsing
int			parsing(t_map *map_struct, t_config *config);
int			check_if_dotcub(char *filename);
int			check_if_xpm(char *filename);
int			check_the_ext(char *filename);
int			map_empty(t_map *map_struct, t_config *config);
int			is_map_valid(t_map *map_struct, t_config *config);
int			is_map_border_closed(t_map *map_struct, t_config *config);
int			is_a_valid_char(t_map *map_struct);
int			is_map_closed(t_map *map_struct);
int			is_whitespace(char c);
int			check_texture_and_color(char *line, t_config *config);
int			under_the_map(t_config *config);

/*FILES*/
int			open_for_the_xpm(char *filename);
int			alloc_and_stock_lines(t_map *map_struct);
int			open_for_the_map(t_map *map_data);

void		actualize_nb_of_col(char *line, int *nb_of_cols);
char		*trim_new_line(char *line);
int			ft_putendl_fd_cub(char *str, int fd);
int			is_whitespace(char c);
int			is_valid_scene_character(char c, t_map *map_struct);

/*Debugg*/
void		print_the_map(char **map);
int			ft_strslen(char **strs);

// Clear
void		free_map_struct(t_map *map_data);
void		free_config(t_config *config);
void		free_tab(char **tab);

/*utils*/
char		*ft_strdup_cub(const char *s1);
int			ft_strlen_cub(const char *s);

//MOVE_CAMERA.c
void    camera_left(t_data *data);
void    camera_right(t_data *data);
//MOVE.c
void    move_forward(t_data *data);
void    move_back(t_data *data);
void    move_left(t_data *data);
void    move_right(t_data *data);
//HANDLE_KEY_PRESS
void    init_keys(t_data *data);
int     key_press(int keycode, t_data *data);
int     key_release(int keycode, t_data *data);
int     handle_keypress(t_data *data);
//RAYCASTING
void	main_raycast(t_data *data, t_image win_img);
void	verLine(t_image image, int x, int y1, int y2, int color);
void    raycast_init_var(t_data *data, int x);
void    raycast_init_raydir(t_data *data);
int		raycast_dda(t_data *data);

//
int     do_frame(t_data *data);
void    init_player_direction(t_data *data);

void    clean_game(t_data *data);

///img
t_image	image_new(void *mlx, size_t w, size_t h);
void	image_put_px(t_image img, int x, int y, int color);
void	image_delete(void	*mlx, t_image img);

// MINIMAP 
void init_minimap(t_data *data);
void draw_minimap(t_data *data);
void update_player_position_on_minimap(t_data *data);
void display_minimap(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif