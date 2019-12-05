/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 03:30:31 by iguidado          #+#    #+#             */
/*   Updated: 2019/12/05 20:41:08 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include "outlib.h"

int	ft_handle_error(int fd, char **line)
{
	if (fd < 0)
		return (1);
	if (!line)
		return (1);
	else
		if (*line)
			free(*line);
	*line = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char buffer[BUFFER_SIZE] = NULL;
	int					ret;

	if(ft_handle_error(fd, line))
		return (-1);
	while (ft_dump_buf(buffer, line) == 1)
	{
		if ((ret = read(fd, buflst->buffer, BUFFER_SIZE)) <= 0)
		{
			if (!ret)
				ft_del_fd(fd, &lst);
			return (ret);
		}
	}
	return (1);
}

/*
**	int	main(void)
**	{
**		char buf[] ="1\n2\n3\n4\n";
**
**	ft_clr_buf(buf);
**	ft_print_memory(buf, BUFFER_SIZE);
**	return (0);
**	}
*/

/*
**	int	main(int argc, char **argv)
**	{
**		int fd;
**		char *line;
**
**		(void)argc;
**		fd = open(argv[1], O_RDONLY, 0);
**		get_next_line(fd, &line);
**		ft_putendl(line);
**		return (0);
**	}
*/

/*
 **	Un petit probleme de boucle infinie qui semble etre due a la fonction clean buffer
 **	ou un autre fonction gérant le buffer et empéchant l'appel supplémentaire de read
 **
 */


	int	test_stdin(int (*gnl)(int, char **))
	{
		char	*line;
		int		ret = 0;
	
		while((ret = gnl(0, &line)))
		{
			if (ret == -1)
				return (-1);
			P('-');
			ft_putnbr(ret);
			P('-');
			ft_putendl(line);
			ft_putendl("------------------------------------");
		}
		ft_putendl("****************************************");
		P('~');
		ft_putnbr(ret);
		P('~');
		ft_putendl(line);
		return (0);
	}
	
	int	test_fd(int fd, int (*gnl)(int, char **))
	{
		int		ret = 0;
		char	*line;
	
		ft_putendl("****************************************");
		while((ret = (*gnl)(fd, &line)))
		{
			if (ret == -1)
			{
				if (line)
					ft_putendl(line);
				ft_putendl("---~ERROR~---");
				return (-1);
			}
			P('-');
			ft_putnbr(ret);
			P('-');
			ft_putendl(line);
			ft_putendl("------------------------------------");
		}
		ft_putendl("****************************************");
		P('~');
		ft_putnbr(ret);
		P('~');
		ft_putendl(line);
		return (0);
	}
	
	#include <fcntl.h>
	
	int	main(int ac, char **av)
	{
		int fd[ac -1];
		int i = 0;
		char *line;
		int	end = 1;
		int count = 1;
	
	
		while (++i < ac)
			fd[i - 1] = open(av[i], O_RDONLY, 0);
		if (ac == 1)
			test_stdin(get_next_line);
		else if (ac == 2)
		{
			test_fd(fd[0], get_next_line);
			return (0);
		}
		else
		{
			while (count)
			{
				i = 0;
				count = 0;
				while (i < (ac - 1))
				{
					if ((end = get_next_line(fd[i], &line)))
					{
						count++;
						ft_putendl("______________________________");
						P('[');
						ft_putnbr(end);
						P(']');
						P('\t');
						P('=');
						P('\t');
						ft_putendl(av[i + 1]);
						ft_putendl(line);
						ft_putendl("______________________________");
					}
					else
					{
						ft_putendl("______________________________");
						P('[');
						ft_putnbr(end);
						P(']');
						P('\t');
						P('=');
						P('\t');
						ft_putendl(av[i + 1]);
						ft_putendl("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
						ft_putendl("______________________________");
					}
					i++;
				}
			}
		}
	return (0);
	}

