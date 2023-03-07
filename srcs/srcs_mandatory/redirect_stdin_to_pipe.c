/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin_to_pipe.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:38:51 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 16:38:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdin_to_pipe(t_data *d)
{
	int	failure;

	failure = dup2(d->file_descriptors.fd[READ_SIDE], STDIN_FILENO);
	if (failure == -1)
		handle_error(d, "dup2");
}
