
#include "cub3D.h"

int	check_if_dotcub(char *filename)
{
	int	len;

	if (filename == NULL)
		return (EXIT_FAILURE);
	len = ft_strlen(filename);
	if (len >= 4 && filename[len - 4] == '.' && filename[len - 3] == 'c' &&
		filename[len - 2] == 'u' && filename[len - 1] == 'b')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	check_if_xpm(char *filename)
{
	int	len;

	if (filename == NULL)
		return (EXIT_FAILURE);
	len = ft_strlen(filename);
	while((filename[len] == ' ') ||(filename[len] == '\0'))
		len--;
	if (len >= 4 && filename[len - 3] == '.' && filename[len - 2] == 'x' &&
		filename[len - 1] == 'p' && filename[len] == 'm')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
