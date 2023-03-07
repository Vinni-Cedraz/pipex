/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:39:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 13:26:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(t_data *d)
{
	int	failure;

	failure = (pipe(d->file_descriptors.fd) == -1);
	if (failure)
		handle_error(d, "pipe");
}
