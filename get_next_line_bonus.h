/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:53:46 by iguidado          #+#    #+#             */
/*   Updated: 2020/12/21 18:44:36 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef	BUFF_SIZE
#  define BUFF_SIZE 1
# endif

typedef	struct	s_lkd_buff
{
	int						fd;
	char					buff[BUFF_SIZE];
	struct	s_lkd_buff	*next;
}				t_lkd_buff;


t_lkd_buff	*ft_create_lkd_buff(int fd, t_lkd_buff *next);
char		*ft_get_node(int fd, t_lkd_buff **node_start);

int			ft_mv_buff(char *buff);
char		*ft_buffdup(char *buff);
char		*ft_linecat(char *line, char *buff);
int			ft_dump_buff(char **line, char *buff);
int			get_next_line(int fd, char **line);

#endif
