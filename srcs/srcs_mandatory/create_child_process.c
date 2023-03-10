/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:44:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/10 16:55:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_first_child_process(t_data *d)
{
	int	id;

	id = fork();
	if (-1 == id)
		handle_error(d, "first fork", &free_error4);
	return (id);
}

int	wait_and_create_second_child(t_data *d)
{
	int	id;

	// wait(0);
	id = fork();
	if (-1 == id)
		handle_error(d, "second_fork", &free_error4);
	return (id);
}
