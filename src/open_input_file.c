/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/02 17:55:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_input_file(t_data *d)
{
	d->pipe.input_fd = open(d->args.file1, O_RDONLY);
	if (d->pipe.input_fd == -1)
		handle_error(d, "open");
}
