#include <unistd.h>
#include "square.h"

void	ft_putstr(char *str);
void	ft_puterr(char *err);

/*
Missing Validation:
◦ There’s at least one line of at least one box.
◦ At each end of line, there’s a line break.
◦ The map is invalid if a character is missing from the first line
  or if two char- acters (of empty, full and obstacle) are identical.
◦ The characters can be any printable character, even numbers.
*/
int	validate_map_character(char buf, t_map *map)
{
	if (buf != '\n' && buf != map->empty && buf != map->obstacle)
	{
		ft_puterr("map error\nThis map contains invalid characters.\n");
		return (0);
	}
	else
		return (1);
}

int	validate_map_columns(int columns[])
{
	if (columns[0] != columns[1])
	{
		ft_puterr("map error\nThis map has an irregular amount of columns.\n");
		return (0);
	}
	return (1);
}

int	validate_map_content(int file_descriptor, int columns[], t_map *map)
{
	char	buf;
	int		i;

	i = 0;
	read(file_descriptor, &buf, 1);
	while (read(file_descriptor, &buf, 1))
	{
		if (buf == '\n' && i == 1)
		{
			if (!validate_map_columns(columns))
				return (0);
			columns[1] = 0;
		}
		else if (buf == '\n' && i == 0)
			i = 1;
		else
			columns[i]++;
		if (!validate_map_character(buf, map))
			return (0);
	}
	map->columns = columns[0];
	return (1);
}
