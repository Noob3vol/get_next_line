/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 03:38:02 by iguidado          #+#    #+#             */
/*   Updated: 2019/11/30 03:43:27 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef	struct	s_buflist
{
	int					fd;
	char				buffer[BUFFER_SIZE];
	struct s_buflist	*next;
}				t_buflist;

t_buflist		*ft_get_fd(t_buflist **buffer, int fd);
int				ft_dump_buf(char **line, char buffer[]);
void			ft_del_fd(int fd, t_buflist **alst);
void			ft_pop_list(t_buflist *buf);

#endif
