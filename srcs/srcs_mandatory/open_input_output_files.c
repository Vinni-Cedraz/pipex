/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input_output_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/08 16:37:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_input_output_files(t_data *d)
{
	t_fds	*fds;

	fds = &d->file_descriptors;
	fds->input_fd = open(d->args.file1, O_RDONLY);
	if (fds->input_fd == -1)
		handle_error(d, "open");
	fds->output_fd = open(d->args.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds->output_fd == -1)
		handle_error(d, "open");
}
