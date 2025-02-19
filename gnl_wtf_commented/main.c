/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romorale <romorale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:40:35 by romorale          #+#    #+#             */
/*   Updated: 2025/02/19 17:22:34 by romorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
//the function call opens the file and should return a non-negative integer 
//representing the lowest numbered unused file descriptor. the fd will 
//typically be larger than 2, since fds 0, 1 and 2 are reserved for the 
//standard imput, output and error respectively. if there's any issue 
//(like opening a file that doesn´t exist, or we don´t have permissions for) 
//open will return -1. 0_RDONLY flag is for the read only access mode.
	fd = open("test.txt", O_RDONLY);
//open shall establish the connection between a file and the newly 
//created file descriptor. This can be used later by other I/O functions 
//to refefr to that file.
	printf("\nfd is: %d\n\n", fd);
	if (fd == -1)
	{
		printf("\nnope\n\n");
		return (0);
	}
//infinite loop, will stop if the return value is null.
	while (1)
	{
		next_line = get_next_line(fd);
//the function will find the first line within the file using the fd.
		if (next_line == NULL)
			break ;
		count++;
		printf("[line number %d]:%s\n", count, next_line);
		free(next_line);
//must free before looping again or breaking the loop when we run out of lines
	}
//the close function deallocates the fd indicated. This makes the fd available
//again for return for another call like open or other functions 
//that allocate fds.
	close(fd);
	printf("-------End of the text file------\n\n");
	return (0);
}
