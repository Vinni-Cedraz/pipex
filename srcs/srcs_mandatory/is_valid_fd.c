/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:14:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/08 15:15:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_valid_fd(int fd)
{
	char	buf;

	return (write(fd, &buf, 0) != -1 || errno != EBADF) ||
		(read(fd, &buf, 0) != -1 || errno != EBADF);
}
