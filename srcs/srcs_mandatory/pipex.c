/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:52:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/08 12:38:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define WRTE_END 1
#define READ_END 0

// is_valid_fd uses fctnl() to check if an fd was already closed
int is_valid_fd(int fd) {
	return fcntl(fd, F_GETFD) != -1 || errno != EBADF;
}

int	main(int argc, char **argv)
{
	char	*full_cmd1;
	char	*full_cmd2;
	char	**cmd1;
	char	**cmd2;
	t_split	*split1;
	t_split	*split2;
	int		i;
	int		id;
	int		input_file_fd;
	int		output_file_fd;
	int		pipe_fds[2];

	i = 0;
	// check argc
	if (argc != 5)
		return (perror("Wrong number of arguments"), -1);

	// split commands from their arguments
	split1 = ft_split(argv[2], ' ');
	split2 = ft_split(argv[3], ' ');

	// get paths create full names
	full_cmd1 = ft_strjoin("/usr/bin/", split1->str_arr[0]);
	full_cmd2 = ft_strjoin("/usr/bin/", split2->str_arr[0]);

	// create NULL terminated **cmd1 for execve
	cmd1 = ft_calloc(sizeof(char *), split1->words + 1);
	cmd1[0] = ft_strdup(split1->str_arr[0]);
	while (++i < (int)split1->words)
		cmd1[i] = ft_strdup(split1->str_arr[i]);
	cmd1[i] = ft_strdup(argv[1]);

	// create NULL terminated **cmd2 for execve
	cmd2 = ft_calloc(sizeof(char *), split2->words + 1);
	cmd2[0] = ft_strdup(split2->str_arr[0]);
	i = 0;
	while (++i < (int)split2->words)
		cmd2[i] = ft_strdup(split2->str_arr[i]);

	// open files
	input_file_fd = open(argv[1], O_RDONLY);
	if (input_file_fd == -1)
		return (perror("couldn't open input_file_fd, ln.72"), -1);
	output_file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file_fd == -1)
		return (perror("couldn't open output_file_fd, ln.75"), -1);

	pipe(pipe_fds);

	// create_child
	id = fork();
	if (id == -1)
		return (perror("couldn't fork, ln.67"), -1);

	// if child
	if (id == 0)
	{

		// close pipe_fds[READ_END]
		if (is_valid_fd(pipe_fds[READ_END]))
			close(pipe_fds[READ_END]);
		// make pipe_fds[WRTE_END] become the stdout of the child
		if (dup2(pipe_fds[WRTE_END], STDOUT_FILENO) == -1)
		  return (perror("couldn't dup2, ln.90"), -1);
		// execute cmd1
		if (is_valid_fd(output_file_fd))
			close(output_file_fd);
		// make input_file_fd become the stdin of the child
		if (dup2(input_file_fd, STDIN_FILENO) == -1)
		  return (perror("couldn't dup2, ln.84"), -1);
		execve(full_cmd1, cmd1, NULL);
		if (is_valid_fd(input_file_fd))
		  close(input_file_fd);
	}

	else // is_parent
	{
		wait(0);
		id = fork();
		if (id == -1)
			return (perror("couldn't fork, ln.99"), -1);
		if (id == 0)
		{ 	
			// is second_child
			if (is_valid_fd(pipe_fds[WRTE_END]))
			  close(pipe_fds[WRTE_END]);
			// make pipe_fds[READ_END] become the stdin of the second child
			if (dup2(pipe_fds[READ_END], STDIN_FILENO) == -1)
			  return (perror("couldn't dup2, ln.106"), -1);
			if (is_valid_fd(input_file_fd))
			  close(input_file_fd);
			if (is_valid_fd(pipe_fds[READ_END]))
			  close(pipe_fds[READ_END]);
			// make output_file_fd become the stdout of the second child
			if (dup2(output_file_fd, STDOUT_FILENO) == -1)
			  return (perror("couldn't dup2, ln.109"), -1);
			// execute cmd2
			execve(full_cmd2, cmd2, NULL);
			if (is_valid_fd(output_file_fd))
			  close(output_file_fd);
			
		}
		close(pipe_fds[READ_END]);
		close(pipe_fds[WRTE_END]);
		close(input_file_fd);
		close(output_file_fd);
		ft_free_t_split(split1);
		ft_free_t_split(split2);
		ft_free_arr(cmd1, (void **)cmd1);
		ft_free_arr(cmd2, (void **)cmd2);
		free(full_cmd1);
		free(full_cmd2);
	}
}
