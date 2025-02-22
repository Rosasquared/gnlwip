/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romorale <romorale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:20:51 by romorale          #+#    #+#             */
/*   Updated: 2025/02/22 16:03:11 by romorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_buffer(char *buffer)
{
	char	*clean_buf;
	char	*n_ptr;
	int		len;

	n_ptr = ft_strchr(buffer, '\n');
	if (!n_ptr)
	{
		clean_buf = NULL;
		return (ft_free(&buffer));
	}
	else
		len = (n_ptr - buffer) + 1;
	if (!buffer[len])
		return (ft_free(&buffer));
	clean_buf = ft_substr(buffer, len, ft_strlen(buffer) - len);
	ft_free(&buffer);
	if (!clean_buf)
		return (NULL);
	return (clean_buf);
}

char	*new_line(char *buffer)
{
	char	*line;
	char	*n_ptr;
	int		len;

	n_ptr = ft_strchr(buffer, '\n');
	len = (n_ptr - buffer + 1);
	line = ft_substr(buffer, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	char	*mini_buf;
	int		chars_read;

	chars_read = 1;
	mini_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!mini_buf)
		return (ft_free(&buffer));
	mini_buf[0] = '\0';
	while (chars_read > 0 && !ft_strchr(mini_buf, '\n'))
	{
		chars_read = read (fd, mini_buf, BUFFER_SIZE);
		if (chars_read > 0)
		{
			mini_buf[chars_read] = '\0';
			buffer = ft_strjoin(buffer, mini_buf);
		}
	}
	free(mini_buf);
	if (chars_read == -1)
		return (ft_free(&buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0)
		return (NULL);
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
		buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	next_line = new_line(buffer);
	if (!next_line)
		return (ft_free(&buffer));
	buffer = clean_buffer(buffer);
	return (next_line);
}
