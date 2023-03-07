/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin_to_file_one.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:30:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 13:27:31 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdin_to_file_one(t_data *d)
{
	int	failure;

	failure = (dup2(d->file_descriptors.input_fd, STDIN_FILENO) == -1);
	if (failure)
		handle_error(d, "dup2");
}
