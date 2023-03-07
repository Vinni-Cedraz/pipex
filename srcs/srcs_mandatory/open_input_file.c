/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 13:27:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_input_file(t_data *d)
{
	printf("file1: %s\n", d->args.file1);
	d->file_descriptors.input_fd = open(d->args.file1, O_RDONLY);
	printf("input_fd: %d\n", d->file_descriptors.input_fd);
	if (d->file_descriptors.input_fd == -1)
		handle_error(d, "open");
}
