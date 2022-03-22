void	print_largest_possible_square(int n_maps, char *map_filenames[]);
void	ft_putstr(char *str);

void	process_input(int n_maps, char *map_filenames[])
{
	char	*_map_filenames;
	int		_n_maps;

	if (n_maps == 1)
	{
		ft_putstr("Please write the names of the files you"
			" have your maps in separated by spaces.\n");
		(void) _n_maps;
		(void) _map_filenames;
	}
	else
	{
		print_largest_possible_square(n_maps, map_filenames);
	}
}
