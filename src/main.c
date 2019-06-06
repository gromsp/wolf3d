
#include "../include/wolf.h"

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (av != 2)
	{
		write(1, "Need map file: .map\n", 20);
		exit(-2);
	}
	parser(av[1]);
	return (0);
}