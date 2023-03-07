/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:03:53 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 14:31:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(t_data *d)
{
	close(d->file_descriptors.fd[0]);
	close(d->file_descriptors.fd[1]);
	close(d->file_descriptors.input_fd);
	close(d->file_descriptors.output_fd);
}
