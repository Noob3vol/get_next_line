/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:53:34 by iguidado          #+#    #+#             */
/*   Updated: 2020/12/21 15:53:36 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef	BUFF_SIZE
#  define BUFF_SIZE 8
# endif

int		ft_mv_buff(char *buff);
char	*ft_buffdup(char *buff);
char	*ft_linecat(char *line, char *buff);
int		ft_dump_buff(char **line, char *buff);
int		get_next_line(int fd, char **line);

#endif
