#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "square.h"

char	*create_map(char *filename, t_map *map_details)
{
	char	*map_string;
	int		i;
	int		file_descriptor;
	char	buffer;

	i = 0;
	file_descriptor = open(filename, O_RDONLY);
	map_string = malloc(map_details->lines \
	* (map_details->columns + 1) + 1);
	while (read(file_descriptor, &buffer, 1))
		if (buffer == '\n')
			break ;
	while (read(file_descriptor, &buffer, 1))
	{
		map_string[i] = buffer;
		i++;
	}
	map_string[i] = '\0';
	return (map_string);
}
