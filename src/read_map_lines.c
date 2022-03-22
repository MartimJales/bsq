#include <unistd.h>

int	ft_isdigit(char c);

char	read_map_lines(int file_descriptor, int *lines)
{
	char	buf;

	buf = '0';
	*lines = 0;
	while (read(file_descriptor, &buf, 1))
	{
		if (ft_isdigit(buf))
		{
			*lines *= 10;
			*lines += buf - '0';
		}
		else
		{
			break ;
		}
	}
	return (buf);
}
