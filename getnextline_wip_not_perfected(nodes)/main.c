/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:39:25 by romorale          #+#    #+#             */
/*   Updated: 2025/01/31 17:33:35 by romorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line!= NULL)
	{
		printf("line: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}

}
