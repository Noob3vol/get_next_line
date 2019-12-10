/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:25:50 by iguidado          #+#    #+#             */
/*   Updated: 2019/12/06 01:03:30 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static void		ft_clr_buf(char buf[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	while (++i < BUFFER_SIZE)
	{
		buf[j] = buf[i];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buf[j] = '\0';
		j++;
	}
}

int			ft_dump_buf(char buffer[], char **line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n' && i < BUFFER_SIZE)
		i++;
	while ((*line) && (*line)[j])
		j++;
	if (!(new = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (-1);
	new[i + j] = '\0';
	i = 0;
	j = 0;
	while ((*line) && (new[j] = (*line)[j]))
		j++;
	while (buffer[i] && buffer[i] != '\n' && i < BUFFER_SIZE)
	{
		new[j + i] = buffer[i];
		i++;
	}
	if (*line)
		free(*line);
	*line = new;
	if (i < BUFFER_SIZE)
		j = (buffer[i] == '\n' ? 0 : 1);
	ft_clr_buf(buffer);
	return (j);
}

/*
**	#include "libft.h"
**	int		main(void)
**	{
**		char buff_test[BUFFER_SIZE] = "0123456789";
**		char *line = NULL;
**		char **line_ptr = &line;
**
**		ft_print_memory((void *)buff_test, BUFFER_SIZE + 1);
**		ft_putnbr(ft_dump_buf(buff_test, line_ptr));
**		P('\n');
**		ft_print_memory((void *)buff_test, BUFFER_SIZE + 1);
**		ft_putendl(line);
**		return (0);
**	}
*/
