/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:57:43 by hrings            #+#    #+#             */
/*   Updated: 2022/01/31 11:30:35 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	findchar(char *s, char c);

char	*get_next_line(int fd)
{
	static t_gnl	*line_save_lst = NULL;
	char			*line;
	t_gnl			*line_save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line_save_lst)
	{
		line_save = newlistitem(fd);
		line_save_lst = line_save;
	}
	else
		line_save = fine_lst_item(line_save_lst, fd);
	line_save = ft_read_file(line_save);
	if (line_save == NULL)
		return (NULL);
	line = ft_find_line(line_save->save);
	line_save->save = remove_line(line_save->save);
	return (line);
}

t_gnl	*ft_read_file(t_gnl *line_save)
{
	char	*read_buff;
	int		read_byte;

	if (line_save->save && findchar(line_save->save, '\n'))
		return (line_save);
	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (NULL);
	read_byte = 1;
	read_buff[0] = '\0';
	while (read_byte > 0 && !findchar(read_buff, '\n'))
	{
		read_byte = read(line_save->fd, read_buff, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(read_buff);
			return (NULL);
		}
		read_buff[read_byte] = '\0';
		line_save->save = ft_strjoin(line_save->save, read_buff);
	}
	free(read_buff);
	return (line_save);
}

char	*ft_find_line(char *line_save)
{
	size_t	index;
	char	*result;

	if (!line_save || !*line_save)
		return (NULL);
	index = 0;
	while (line_save[index] && line_save[index] != '\n')
		index++;
	result = malloc(sizeof(char) * (index + 2));
	if (!result)
		return (NULL);
	index = 0;
	while (line_save[index] && line_save[index] != '\n')
	{
		result[index] = line_save[index];
		index++;
	}
	if (line_save[index] == '\n')
	{
		result[index] = line_save[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

char	*remove_line(char *line_save)
{
	size_t	index;
	size_t	index2;
	char	*result;

	if (!line_save)
		return (NULL);
	index = 0;
	while (line_save[index] != '\n' && line_save[index] != '\0')
		index++;
	if (!line_save[index])
	{
		free(line_save);
		return (NULL);
	}
	result = malloc(sizeof(char) * (ft_strlen(line_save) - index + 1));
	if (!result)
		return (NULL);
	index2 = 0;
	while (line_save[++index] != '\0')
	{
		result[index2++] = line_save[index];
	}
	result[index2] = '\0';
	free(line_save);
	return (result);
}

static int	findchar(char *s, char c)
{
	size_t	index;

	index = 0;
	while (*(s + index))
	{
		if (*(s + index) == c)
			return (1);
		index++;
	}
	return (0);
}
