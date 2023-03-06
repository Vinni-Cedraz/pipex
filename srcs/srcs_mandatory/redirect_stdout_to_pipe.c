/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout_to_pipe.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:22:07 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 19:52:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdout_to_pipe(t_data *d)
{
	short	failure;

	failure = dup2(d->pipe.fd[WRTE_SIDE], STDOUT_FILENO);
	if (failure == -1)
		handle_error(d, "dup2");
	close(d->pipe.fd[WRTE_SIDE]);
}
