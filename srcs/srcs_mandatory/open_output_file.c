/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_output_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:40:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 19:49:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_output_file(t_data *d)
{
	d->pipe.output_fd = open(d->args.file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->pipe.output_fd == -1)
		handle_error(d, "open");
}
