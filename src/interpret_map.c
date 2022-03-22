#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "square.h"

char	read_map_lines(int file_descriptor, int *lines);
int		validate_map(int file_descriptor, char *map_filename, \
t_map *map, char *map_string);
void	ft_putstr(char *str);
void	ft_puterr(char *err);

void	interpret_map(char *filename, t_map *map, char *map_string)
{
	int		file_descriptor;

	file_descriptor = open(filename, O_RDONLY);
	if (0 < file_descriptor)
	{
		map->empty = read_map_lines(file_descriptor, &map->lines);
		read(file_descriptor, &map->obstacle, 1);
		read(file_descriptor, &map->full, 1);
		map->columns = validate_map(file_descriptor, \
		filename, map, map_string);
		if (map->columns)
		{
			ft_putstr("Succesfully validated map.\n");
		}
		close(file_descriptor);
	}
	else
	{
		ft_putstr("Couldn't open file \"");
		ft_putstr(filename);
		ft_putstr("\"!\n");
	}
}
