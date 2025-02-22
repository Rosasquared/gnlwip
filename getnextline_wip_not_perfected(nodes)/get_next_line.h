/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romorale <romorale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:55:31 by romorale          #+#    #+#             */
/*   Updated: 2025/01/31 14:03:54 by romorale         ###   ########.fr       */
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
#  define BUFFER_SIZE 10
# endif

typedef struct s_list	t_list;
struct s_list
{
	char	*str_buf;
	t_list	*next;
};

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
char	*get_the_line(t_list *list);
void	append(t_list **list, char *buf);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
void	polish_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
t_list	*find_last_node(t_list *list);
int		found_newline(t_list *list);

#endif
