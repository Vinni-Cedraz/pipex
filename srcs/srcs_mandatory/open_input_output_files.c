/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input_output_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:34:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/11 21:37:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_input_output_files(t_data *d)
{
	t_fds	*fds;

	fds = &d->file_descriptors;
	if (-1 == access(d->args.file1, R_OK | F_OK))
		handle_error(d, "input file access", &custom_free2, 2);
	fds->input_fd = open(d->args.file1, O_RDONLY);
	if (-1 == fds->input_fd)
		handle_error(d, "open input file", &custom_free2, 2);
	fds->output_fd = open(d->args.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (-1 == fds->output_fd)
		handle_error(d, "open output file", &custom_free2, 2);
}
