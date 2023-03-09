/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:33:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/09 08:22:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			create_pipe(t_data *d);

int	main(int argc, char **argv)
{
	t_data	*d;
	int		id;

	d = (t_data *)malloc(sizeof(t_data));
	init_data_for_execve(d, argv, argc);
	open_input_output_files(d);
	create_pipe(d);
	id = create_first_child_process(d);
	if (is_child_process(id))
		run_first_child_process(d);
	else if (is_parent(id))
	{
		id = wait_and_create_second_child(d);
		if (is_child_process(id))
			run_second_child_process(d);
		else
			continue_parent_process(d);
	}
}

static inline void	create_pipe(t_data *d)
{
	if (-1 == pipe(d->file_descriptors.fd))
		handle_error(d, "pipe");
}
