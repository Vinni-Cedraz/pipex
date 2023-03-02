#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "pipex.h"

char	**my_split(char const *s, char c);

void	run_cmd(char *cmd, int in_fd, int out_fd)
{
	char	**args;
	char	*path;

	args = my_split(cmd, ' ');
	path = find_executable(args[0]);
	if (!path)
	{
		fprintf(stderr, "pipex: command not found: %s\n", args[0]);
		exit(EXIT_FAILURE);
	}
	dup2(in_fd, STDIN_FILENO);
	if (out_fd != STDOUT_FILENO)
		dup2(out_fd, STDOUT_FILENO);
	execve(path, args, NULL);
	perror("pipex: execve");
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	int		fd_in;
	int		fd_out;
	int		p[2];
	pid_t	pid;
	int		i;
	char	*cmd;

	if (argc < 5)
	{
		fprintf(stderr, "Usage: %s file1 cmd1 cmd2 ... cmdn file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Open input file */
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror("pipex: open");
		exit(EXIT_FAILURE);
	}

	/* Open output file */
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("pipex: open");
		exit(EXIT_FAILURE);
	}

	for (i = 2; i < argc - 1; i++)
	{
		/* Create pipe */
		if (pipe(p) < 0)
		{
			perror("pipex: pipe");
			exit(EXIT_FAILURE);
		}

		/* Fork process */
		pid = fork();
		if (pid < 0)
		{
			perror("pipex: fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process */
			close(p[0]); /* Close unused read end of the pipe */
			run_cmd(argv[i], fd_in, p[1]); /* Execute command */
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Parent process */
			close(p[1]); /* Close unused write end of the pipe */
			close(fd_in); /* Close unused input file descriptor */
			fd_in = p[0]; /* Set input file descriptor to the read end of the pipe */
		}
	}

	/* Last command writes to output file */
	dup2(fd_out, STDOUT_FILENO);
	run_cmd(argv[argc - 2], fd_in, STDOUT_FILENO);

	exit(EXIT_SUCCESS);
}
