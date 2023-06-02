/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:21:23 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/07 00:21:28 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_manage_buf(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
	{
		buf[i] = '\0';
		i++;
	}
	if (buf[i] == '\0')
		return (0);
	while (++i < BUFFER_SIZE)
	{
		buf[j] = buf[i];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buf[j] = 0;
		j++;
	}
	return (1);
}

int	ft_dump_line(char *buf, char **line)
{
	int		i;
	int		j;
	char	*new;

	if (!*buf)
		return (0);
	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	while ((*line) && (*line)[j])
		j++;
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	new[i + j] = 0;
	while (i-- > 0)
		new[j + i] = buf[i];
	while (j-- > 0)
		new[j] = (*line)[j];
	if (*line)
		free(*line);
	*line = new;
	return (ft_manage_buf(buf));
}
