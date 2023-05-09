/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:33:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/08 22:35:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			create_pipe(t_data *d);
static void			check_args(int argc, char **argv);

int	main(int argc, char **argv, char **envp)
{
	t_data	*d;
	int		id;

	check_args(argc, argv);
	d = (t_data *)malloc(sizeof(t_data));
	init_data_for_execve(d, argv, envp);
	open_input_output_files(d);
	create_pipe(d);
	id = create_first_child_process(d);
	if (is_child_process(id))
		run_first_child_process(d);
	else if (is_parent(id))
	{
		id = create_second_child(d);
		if (is_child_process(id))
			run_second_child_process(d);
		else if (is_parent(id))
			standard_free_function(d);
	}
}

static void	create_pipe(t_data *d)
{
	if (-1 == pipe(d->file_descriptors.fd))
		handle_error(d, "create pipe", &custom_free2, EXIT_FAILURE);
}

static void	check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		printf("Error: Wrong number of arguments.\n");
		exit(EXIT_FAILURE);
	}
	else if (*argv[1] == '\0' || *argv[2] == '\0' || *argv[3] == '\0'
		|| *argv[4] == '\0')
	{
		printf("Error: Invalid Argument\n");
		exit(EXIT_FAILURE);
	}
}
