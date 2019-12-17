#include <unistd.h>
#include <stdlib.h>

void	ft_manage_buf(char *buf)
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
		buf[j] = 0;
		j++;
	}
}

int	ft_dump_line(char *buf, char **line)
{
	int i;
	int j;
	int ret;
	char *new;

	if (!*buf)
		return (0);
	i = 0;
	j = 0;
	ret = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	while ((*line) && (*line)[j])
		j++;
	if (buf[i] == '\n')
		ret = 1;
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	new[i + j] = 0;
	while (i-- > 0)
		new[j + i] = buf[i];
	while (j-- > 0)
		new[j] = (*line)[j];
	if (*line)
		free(*line);
	*line = new;
	ft_manage_buf(buf);
	return (ret);
}
	
int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int		ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	ret = 0;
	while (!ft_dump_line(buff, line))
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) < 1)
		{
			if (ret == -1)
			{
				if (*line)
					free(*line);
				line = NULL;
			}
			return (ret);
		}
	}
	return (1);
}


/*
**	#include <fcntl.h>
**	#include <stdio.h>
**	#include "libft.h"
**
**	int	unit_test_ft_arr_buf(void)
**	int	main(void)
**	{
**		char sample[BUFFER_SIZE] = "Hello\nWorl";
**	
**		ft_arr_buf(sample);
**		ft_print_memory((void *)sample, sizeof(sample));
**		return (0);
**	}
*/

/*
** La compilation se fait sans DFLAG car il y aura toujours des leaks lié
** à la reutilisation de la variable *line pour stocké la ligne
** donc un leak de *line à chaque appel
*/
/*
**	int	strequ(char *str, char *ref)
**	{
**		int i;
**	
**		i = 0;
**		while (str[i])
**		{
**			if (str[i] != ref[i])
**				return (0);
**			i++;
**		}
**		return (1);
**	}
**	
**	int	test_read_1_file(int (*gnl)(int, char **), int fd)
**	{
**		char *line = NULL;
**		int ret = 1;
**		int count = 0;
**		char ref[] = "a";
**	
**		while (count < 25)
**		{
**			ret = gnl(fd, &line);
**			printf("-[%d]-\t%s\n", ret, line);
**			if (!strequ(line, ref))
**				return (printf("Bad line Assignement"));
**			if (ret != 1)
**				return (printf("Mauvais retour de gnl"));
**			ref[0] += 1;
**			count++;
**		}
**		ret = gnl(fd, &line);
**		printf("-[%d]-\t%s\n", ret, line);
**		if (!strequ(line, ref))
**			return (printf("Bad line Assignement"));
**		if (ret != 0)
**			return (printf("Mauvais retour de gnl"));
**		return (0);
**	}
**	
**	int	test_exception(int (*gnl)(int, char **), int fd)
**	{
**		int ret;
**		char *line = NULL;
**	
**		ret = gnl(-30, &line);
**		if (line)
**			return(printf("Line Assignement on ERROR\n"));
**		if (ret != -1)
**			return (printf("Bad Return on ERROR\n%d instead of -1\n", ret));
**		ret = gnl(fd, NULL);
**		if (line)
**			return(printf("Line Assignement on ERROR\n"));
**		if (ret != -1)
**			return (printf("Bad Return on ERROR\n%d instead of -1\n", ret));
**		return (0);
**	}
**	
**	int	main(void)
**	{
**		int fd;
**		char	*line = NULL;
**	
**		fd = open("test.txt", O_RDONLY, 0);
**		test_exception(get_next_line, fd);
**		fd = open("test.txt", O_RDONLY, 0);
**		test_read_1_file(get_next_line, fd);
**		printf("-[%d]-\t%s", get_next_line(fd, &line), line);
**		//	ft_putendl("BUFFER_SIZE ERROR non handled");
**	//	fd = open("test.txt", O_RDONLY, 0);
**	//	test_read_2_file(get_next_line, fd);
**		return (0);
**	}
*/
