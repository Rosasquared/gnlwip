/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romorale <romorale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:20:51 by romorale          #+#    #+#             */
/*   Updated: 2025/02/19 19:13:01 by romorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//this is obvious what its for
char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_buffer(char *buffer)
{
//where we store the remaining chars from after the newline,
//which will be returned as the main buffer for the next loop
	char	*clean_buf;
//tha position of that newline
	char	*n_ptr;
//length of everything before the newline so we can copy from the end onwards
	int		len;
//we find the position of the newline char
	n_ptr = ft_strchr(buffer, '\n');
	if (!n_ptr)
	{
		clean_buf = NULL;
		return (ft_free(&buffer));
	}
	else
//we get the length by subtracting the position of the newline and buffer +1
		len = (n_ptr - buffer) + 1;
	if (!buffer[len])
		return (ft_free(&buffer));
//this buffer will store now the remaining chars, from after the newline by
//using the len of the position of the newline as a starting point and the
//length of what come after it, obtaining a sub_string thats copied into
//this buffer so we dont loose them, cause we need them for the next line
	clean_buf = ft_substr(buffer, len, ft_strlen(buffer) - len);
//we free the main buffer so it can store the remaining chars for use in the next loop
	ft_free(&buffer);
	if (!clean_buf)
		return (NULL);
//we return the cleaned up line without the chars before the newline
	return (clean_buf);
}

char	*new_line(char *buffer)
{
//where we will copy the full line that ends in newline
	char	*line;
//where we store the pointer of the newline in buffer
	char	*n_ptr;
//the length of the full line that ends in newline within the buffer
	int		len;
//we find the position of a new line in buffer using strchr
	n_ptr = ft_strchr(buffer, '\n');
//we get the length of that full line using the position minus the length
//of the buffer + 1
	len = (n_ptr - buffer + 1);
//we store in line the sub_string we get from shortening the string
//using the length
	line = ft_substr(buffer, 0, len);
	if (!line)
		return (NULL);
//we return that sub-string we obtained
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
//mini buffer for storing the read chars from the fd linked to the file
//then we join it to the main buffer
	char	*mini_buf;
//int that will store the amount of bytes by assinging its value through
//the read function
	int		chars_read;
//giving it a value of one for starters
	chars_read = 1;
//reserving memory space with the size of buffersize
	mini_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!mini_buf)
		return (ft_free(&buffer));
//keeping it terminated for now
	mini_buf[0] = '\0';
//if chars_read is more than 0 AND we cant find a newline in the soon to be 
//filled mini_buf
	while (chars_read > 0 && !ft_strchr(mini_buf, '\n'))
	{
//by doing this, we assign the bytes read value and we also read from the
//fd a buffersize amount that is pointed to the mini_buf
		chars_read = read (fd, mini_buf, BUFFER_SIZE);
		if (chars_read > 0)
		{
//if this is successful, we terminate it again  but with the amount read
			mini_buf[chars_read] = '\0';
//we join the mini_buf the the main buffer, that remembers where it
//left it off, if this is not the first time
			buffer = ft_strjoin(buffer, mini_buf);
		}
	}
//we have no more use for mini_buf
	free(mini_buf);
//error handler if read fails and returns -1
	if (chars_read == -1)
		return (ft_free(&buffer));
//we return the main buffer that contains what we joined from mini_buf
	return (buffer);
}

char	*get_next_line(int fd)
{
//main buffer where we will copy a buffersize amount of chars from 
//the file, it will continue from the position where it stopped and 
//doesn´t start again from the beggining with every loop
	static char	*buffer;
//where we will copy from the main buffer a full line that ends in
//newline and be retuned at the end of this funtion before looping
//again in the main for the next one
	char		*next_line;

//check if fd is not negative, for errors
	if (fd < 0)
		return (NULL);
//check if buffer AND if buffer doesn´t contain a newline 
//OR empty buffer
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
//the function that reads the fds file and copies into the main buffer
		buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
//will find the position of a newline in buffer and return a sub string
//taken from buffer based on the position of that newline within the string
	next_line = new_line(buffer);
	if (!next_line)
		return (ft_free(&buffer));
//will remove the all the chars befor a newline in buffer and leave the 
//ones after the newline to keep in buffer for the next loop
	buffer = clean_buffer(buffer);
//we return next_line which is a full line that ends in newline,
//then with the loop we start again from were we left it off in the main
//buffer that still has the chars after the previous newline
	return (next_line);
}
