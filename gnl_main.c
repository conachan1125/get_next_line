#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*line = NULL;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	i = 1;
	while (i)
	{
		i = get_next_line(fd, &line);
		printf("%s", line);
		free(line);
		line = NULL;
	}
}
