/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 03:38:02 by iguidado          #+#    #+#             */
/*   Updated: 2020/01/18 00:17:00 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

int				get_next_line(int fd, char **line);

typedef	struct	s_buflist
{
	int					fd;
	char				buffer[BUFFER_SIZE + 1];
	struct s_buflist	*next;
}				t_buflist;

t_buflist		*ft_get_fd(t_buflist **buffer, int fd);
void			ft_del_fd(int fd, t_buflist **alst);

#endif
