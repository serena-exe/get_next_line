#include "get_next_line.h"
#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	// int	fd2;
	char	*line;

	fd = open("f3.txt", O_RDONLY);
	// fd2 = open("f2.txt", O_RDONLY);
	
	line = get_next_line(fd);
	// printf("%s", line);
	// free(line);

	// while (line)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	
	// line = get_next_line(fd2);
	// while (line)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd2);
	// }
	
	close(fd);
	// close(fd2);
	return (0);
}

