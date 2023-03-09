/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_parent_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:45:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/09 08:30:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			destroy_data(t_data *d);
static void			close_fds(t_data *d);

void	continue_parent_process(t_data *d)
{
	close_fds(d);
	destroy_data(d);
}

static inline void	close_fds(t_data *d)
{
	close(d->file_descriptors.input_fd);
	close(d->file_descriptors.output_fd);
	close(d->file_descriptors.fd[READ_SIDE]);
	close(d->file_descriptors.fd[WRTE_SIDE]);
}

static inline void	destroy_data(t_data *d)
{
	ft_free_arr(d->execve.str_arr1, (void **)d->execve.str_arr1);
	ft_free_arr(d->execve.str_arr2, (void **)d->execve.str_arr2);
	ft_free_t_split(d->split1);
	ft_free_t_split(d->split2);
	free(d);
}
