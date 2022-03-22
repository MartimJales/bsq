#include <stdlib.h>
#include "square.h"

void	interpret_map(char *map_filename, t_map *map_details);
char	*create_map(char *map_filename, t_map *map_details);

void	print_largest_possible_square(int n_maps, char *map_filenames[])
{
	int		i;
	t_map	*map_details;
	char	*map_string;

	map_details = malloc(sizeof(t_map));
	i = 0;
	while (i < n_maps - 1)
	{
		interpret_map(map_filenames[i + 1], map_details);
		map_string = create_map(map_filenames[i + 1], map_details);
		// here goes algorithm
		free(map_string);
		i++;
	}
	free(map_details);
}
