/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:14:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/09 17:06:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

inline int	is_valid_fd(int fd)
{
	char	buf;
	short	invalid_read;
	short	invalid_write;

	invalid_read = (write(fd, &buf, 0) != -1 || errno != EBADF);
	invalid_write = (read(fd, &buf, 0) != -1 || errno != EBADF);
	return (!invalid_read || !invalid_write);
}

inline void	close_fd(int fd)
{
	if (is_valid_fd(fd))
		close(fd);
}
