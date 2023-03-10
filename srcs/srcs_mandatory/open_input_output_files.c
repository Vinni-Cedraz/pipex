/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input_output_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/09 22:51:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_input_output_files(t_data *d)
{
	t_fds	*fds;

	fds = &d->file_descriptors;
	if (-1 == access(d->args.file1, R_OK))
		handle_error(d, "can't access input file", &free_error2);
	fds->input_fd = open(d->args.file1, O_RDONLY);
	if (fds->input_fd == -1)
		handle_error(d, "open input file", &free_error2);
	fds->output_fd = open(d->args.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds->output_fd == -1)
		handle_error(d, "open output file", &free_error3);
}
