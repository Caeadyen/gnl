/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:58:10 by hrings            #+#    #+#             */
/*   Updated: 2022/01/21 12:24:16 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*result;
	const size_t	length_s1 = ft_strlen(s1);
	const size_t	length_s2 = ft_strlen(s2);
	size_t			index;
	size_t			index2;

	result = (char *)malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	index = 0;
	index2 = 0;
	while (s1 && s1[index2] != '\0')
		result[index++] = s1[index2++];
	index2 = 0;
	while (s2 && s2[index2] != '\0')
		result[index++] = s2[index2++];
	free(s1);
	result[length_s1 + length_s2] = '\0';
	return (result);
}

int	ft_strlen(const char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	listadd(t_gnl *list, t_gnl *newitem)
{
	if (list != NULL && newitem != NULL)
	{
		newitem->next = list->next;
		list->next = newitem;
	}
}

t_gnl	*newlistitem(int fd)
{
	t_gnl	*result;

	result = (t_gnl *)malloc(sizeof(t_gnl));
	if (!result)
		return (NULL);
	result->fd = fd;
	result->next = NULL;
	result->save = NULL;
	return (result);
}

t_gnl	*fine_lst_item(t_gnl *line_save_lst, int fd)
{
	t_gnl	*result;

	result = line_save_lst;
	while (result)
	{
		if (result->fd == fd)
			return (result);
		if (!result->next)
		{
			listadd(result, newlistitem(fd));
			return (result->next);
		}
		result = result->next;
	}
	return (NULL);
}
