#include <unistd.h>
#include <stdlib.h>

int	ft_manage_buf(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
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
	int i;
	int j;
	char *new;

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
