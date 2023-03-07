/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_output_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:40:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 21:41:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_output_file(t_data *d)
{
	printf("file2: %s\n", d->args.file2);
	d->pipe.output_fd = open(d->args.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("output_fd: %d\n", d->pipe.output_fd);
	if (d->pipe.output_fd == -1)
		handle_error(d, "open");
}
