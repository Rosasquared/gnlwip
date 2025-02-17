#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*next_line;
	int	count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	printf("\nfd is: %d\n\n", fd);
	if (fd == -1)
	{
		printf("\nnope\n\n");
		return (0);
	}

	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[line number %d]:%s\n", count, next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}

