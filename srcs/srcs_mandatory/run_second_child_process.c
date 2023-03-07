/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_second_child_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:44:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 16:18:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_second_child_process(t_data *d)
{
	create_child_process(d);
	if (!is_child_process(d->fork.id))
		return ;
	redirect_stdin_to_pipe(d);
	redirect_stdout_to_file_two(d);
	execute_second_command(d);
}
