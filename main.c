#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#ifndef BONUS
# define BONUS 0
#endif

void	ft_test(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		printf("filename = %s\n------------------------------\n\n", av[i]);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%d ~~> %s\n", ret, line);
			free(line);
		}
		printf("%d ~~> %s\n\n", ret, line);
		i++;
	}
}

void	ft_test_bonus(int ac, char **av)
{
	int		fd[ac];
	char	*line;
	int		ret;
	int		i;

	i = 0;
	while (i < ac)
	{
		fd[i] = open(av[i], O_RDONLY);
		i++;
	}
	ret = 1;
	while (ret)
	{
		ret = 0;
		i = 0;
		while (i < ac)
		{
			printf("filename = %s\n------------------------------\n\n", av[i]);
			ret |= get_next_line(fd[i], &line);
			printf("%d ~~> %s\n", ret, line);
			free(line);
			i++;
		}
	}
}

int		main(int ac, char **av)
{

	if (ac == 1)
		return (write(1, "Error\n", 6));
	if (BONUS)
		ft_test_bonus(ac - 1, &av[1]);
	else
		ft_test(ac, av);
	return (0);
}
