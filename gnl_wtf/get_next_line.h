#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char    *get_next_line(int fd);
char    *read_buffer(int fd, char *buffer);
char    *new_line(char *buffer);
char    *clean_buffer(char *buffer);
char    *ft_free(char **str);
char    *ft_strchr(char *str, int c);
char    *ft_substr(char *s, unsigned int start, size_t len);
size_t  ft_strlen(char *s);
char    *ft_strjoin(char *s1, char *s2);

#endif
