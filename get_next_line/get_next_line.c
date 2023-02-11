/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:15:59 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/11/24 14:37:02 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*pile_up(int fd, char *pile)
{
	char		*buffer;
	ssize_t		rbyte;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	rbyte = BUFFER_SIZE;
	while (rbyte && !ft_strchr(pile, '\n'))
	{
		rbyte = read(fd, buffer, BUFFER_SIZE);
		if (rbyte == -1)
		{
			free(buffer);
			free(pile);
			return (NULL);
		}
		buffer[rbyte] = '\0';
		if (pile == NULL)
			pile = ft_strdup(buffer);
		else
			pile = ft_strjoin(pile, buffer);
	}
	free(buffer);
	return (pile);
}

static char	*allocate(char *pile, ssize_t i)
{
	char	*tmp;

	if (ft_strchr(pile, '\n'))
		tmp = (char *)malloc(sizeof(char) * (i + 2));
	else
		tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	return (tmp);
}

static char	*get_line(char *pile)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	if (pile[i] == '\0')
		return (NULL);
	while (pile[i] != '\0' && pile[i] != '\n')
		i++;
	tmp = allocate(pile, i);
	if (!tmp)
		return (NULL);
	i = 0;
	while (pile[i] != '\0' && pile[i] != '\n')
	{
		tmp[i] = pile[i];
		i++;
	}
	if (pile[i] == '\n')
	{
		tmp[i] = pile[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*reset(char *pile)
{
	char	*tmp;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (pile[i] != '\0' && pile[i] != '\n')
		i++;
	if (pile[i] == '\0' || (pile[i] == '\n' && pile[i + 1] == '\0'))
	{
		free(pile);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(pile) - i));
	if (!tmp)
	{
		free(pile);
		return (NULL);
	}
	i++;
	j = 0;
	while (pile[i] != '\0')
		tmp[j++] = pile[i++];
	tmp[j] = '\0';
	free(pile);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*pile;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pile = pile_up(fd, pile);
	if (!pile)
		return (NULL);
	line = get_line(pile);
	pile = reset(pile);
	return (line);
}
