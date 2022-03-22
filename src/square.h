#ifndef SQUARE_H
# define SQUARE_H

typedef struct _map
{
	int		lines;
	int		columns;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct _square
{
	int	x;
	int	y;
	int	size;
}	t_square;

#endif // STRUCTS_H
