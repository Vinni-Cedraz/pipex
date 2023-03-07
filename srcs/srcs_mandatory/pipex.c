/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:52:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 19:41:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define WRTE_END 1
#define READ_END 0

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
		return (perror("Wrong number of arguments"), 0);
	// create NULL terminated **cmds for execve
	split1 = ft_split(argv[2], ' ');
	split2 = ft_split(argv[3], ' ');
	full_cmd1 = ft_strjoin("/usr/bin/", split1->str_arr[0]);
	full_cmd2 = ft_strjoin("/usr/bin/", split2->str_arr[0]);
	cmd1 = ft_calloc(sizeof(char *), split1->words + 1);
	cmd1[0] = split1->str_arr[0];
	while (++i < (int)split1->words)
		cmd1[i] = split1->str_arr[i];
	cmd1[i] = ft_strdup(argv[1]);
	cmd2 = ft_calloc(sizeof(char *), split2->words + 1);
	cmd2[0] = split2->str_arr[0];
	i = 0;
	while (++i < (int)split2->words)
		cmd2[i] = split2->str_arr[i];
	printf("cmd1[0]: %s\n", cmd1[0]);
	printf("cmd1[1]: %s\n", cmd1[1]);
	printf("cmd1[2]: %s\n", cmd1[2]);
	printf("cmd2[0]: %s\n", cmd2[0]);
	printf("cmd2[1]: %s\n", cmd2[1]);
	printf("cmd2[2]: %s\n", cmd2[2]);
	printf("cmd2[3]: %s\n", cmd2[3]);
	// create_child
	id = fork();
	if (id == -1)
		return (perror("couldn't fork"), 0);
	// open files
	input_file_fd = open(argv[1], O_RDONLY);
	output_file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// create pipe
	pipe(pipe_fds);
	// if child
	if (id == 0)
	{ 
		// make input_file_fd become the stdin of the child
		dup2(input_file_fd, STDIN_FILENO);
		// close pipe_fds[READ_END]
		dup2(pipe_fds[WRTE_END], STDOUT_FILENO);
		// execute cmd1
		execve(full_cmd1, cmd1, NULL);
	}
	else
	{
		wait(NULL);
		// close write end
		dup2(pipe_fds[READ_END], STDIN_FILENO);
		// make output_file_fd become the stdout of the parent
		dup2(output_file_fd, STDOUT_FILENO);
		// execute cmd2
		execve(full_cmd2, cmd2, NULL);
	}
	return (0);
}
