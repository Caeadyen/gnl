/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:57:57 by hrings            #+#    #+#             */
/*   Updated: 2022/01/20 10:38:04 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *line_save);
char	*ft_find_line(char *line_save);
char	*remove_line(char *line_save);
int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);

#endif