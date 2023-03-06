/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:44:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/02 13:57:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_child_process(t_data *d)
{
	short	failure;

	d->fork.id = fork();
	failure = (d->fork.id == -1);
	if (failure)
		handle_error(d, "fork");
}
