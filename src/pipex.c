#include "pipex.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	init_args(d, argv, argc);
	create_pipe(d);
	create_child_process(d);
	if (is_child_process(d->fork.id))
	{
		open_input_file(d);
		redirect_stdout_to_pipe(d);
		redirect_stdin_to_file_one(d);
		execute_first_command(d);
		close(d->pipe.input_fd);
	}
	wait(0);
	free(d);
}
