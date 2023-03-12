/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:26:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/11 21:48:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			local_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	local_putstr_fd(s, fd);
	local_putstr_fd("\n", fd);
}

static inline int	local_putstr_fd(char *s, int fd)
{
	int	res;

	while (s && *s)
		res += write(fd, s++, 1);
	return (res);
}
