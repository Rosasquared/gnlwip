/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romorale <romorale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:56:54 by romorale          #+#    #+#             */
/*   Updated: 2025/02/19 15:59:24 by romorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10
# endif

char	*get_next_line(int fd);
char	*read_buffer(int fd, char *buffer);
char	*new_line(char *buffer);
char	*clean_buffer(char *buffer);
char	*ft_free(char **str);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);

#endif
