/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:57:57 by hrings            #+#    #+#             */
/*   Updated: 2022/01/20 11:34:27 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

typedef struct s_gnl
{
	struct s_gnl	*next;
	char			*save;
	int				fd;
}					t_gnl;
char	*get_next_line(int fd);
t_gnl	*ft_read_file(t_gnl *line_save);
char	*ft_find_line(char *line_save);
char	*remove_line(char *line_save);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
void	listadd(t_gnl *list, t_gnl *newitem);
t_gnl	*newlistitem(int fd);
t_gnl	*fine_lst_item(t_gnl *line_save_lst, int fd);

#endif