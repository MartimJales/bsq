#include <unistd.h>
#include <fcntl.h>
#include "square.h"

void	ft_putstr(char *str);
void	ft_puterr(char *err);
int		validate_map_content(int file_descriptor, int columns[], t_map *map);

int	validate_map(int file_descriptor, char *map_filename, t_map *map)
{
	char	buf;
	int		columns[2];

	buf = '\0';
	columns[0] = 0;
	columns[1] = 0;
	if (map->lines == 0)
	{
		ft_puterr("map error\nThis map contains 0 lines.\n");
		return (0);
	}
	if (!validate_map_content(file_descriptor, columns, map))
		return (0);
	close(file_descriptor);
	file_descriptor = open(map_filename, O_RDONLY | O_EXCL);
	while (buf != '\n')
		read(file_descriptor, &buf, 1);
	return (1);
}
