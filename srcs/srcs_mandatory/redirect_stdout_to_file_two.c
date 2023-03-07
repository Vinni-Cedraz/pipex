/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout_to_file_two.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:39:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 16:42:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdout_to_file_two(t_data *d)
{
	int	failure;

	failure = dup2(d->file_descriptors.output_fd, STDOUT_FILENO);
	if (failure == -1)
		handle_error(d, "dup2");
}
