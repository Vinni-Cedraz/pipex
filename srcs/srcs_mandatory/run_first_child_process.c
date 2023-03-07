/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_first_child_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:43:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 15:20:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_first_child_process(t_data *d)
{
	create_child_process(d);
	if (!is_child_process(d->fork.id))
		return ;
	redirect_stdin_to_file_one(d);
	close(d->file_descriptors.fd[READ_SIDE]);
	redirect_stdout_to_pipe(d);
	execute_first_command(d);
	close(d->file_descriptors.fd[WRTE_SIDE]);
}
