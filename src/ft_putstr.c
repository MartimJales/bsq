#include <unistd.h>

int	ft_strlen(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

void	ft_puterr(char *err)
{
	int	len;

	len = ft_strlen(err);
	write(2, err, len);
}
