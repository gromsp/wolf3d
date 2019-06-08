
#include "../include/wolf.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "Need map file: .map\n", 20);
		return(-2);
	}
	parser(av[1]);
	return (0);
}
