/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:33:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 16:28:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	init_data(d, argv, argc);
	open_input_file(d);
	open_output_file(d);
	create_pipe(d);
	run_first_child_process(d);
	continue_parent_process(d);
}
