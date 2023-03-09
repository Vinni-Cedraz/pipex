/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:14:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/09 16:53:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

inline int	is_valid_fd(int fd)
{
	char	buf;
	short	is_valid_read;
	short	is_valid_write;

	is_valid_read = (write(fd, &buf, 0) != -1 || errno != EBADF);
	is_valid_write = (read(fd, &buf, 0) != -1 || errno != EBADF);
	return (is_valid_read || is_valid_write);
}

inline void	close_fd(int fd)
{
	if (is_valid_fd(fd))
		close(fd);
}
