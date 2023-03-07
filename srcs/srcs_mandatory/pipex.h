/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:52:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 21:40:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_SIDE 0
# define WRTE_SIDE 1

# include "../../libs/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_args
{
	char			*file1;
	char			*file2;
	char			*cmd1;
	char			*cmd2;
	char			*cmd2_arg;
	int				argc;
}					t_args;

typedef struct s_fork
{
	int				id;
}					t_fork;

typedef struct s_execve
{
	char			**cmd1_argv;
	char			**cmd2_argv;
}					t_execve;

typedef struct s_pipe
{
	int				fd[2];
	int				input_fd;
	int				output_fd;
	char			*full_cmd1;
	char			*full_cmd2;
}					t_pipe;

typedef struct s_data
{
	t_split			*split;
	t_args			args;
	t_pipe			pipe;
	t_fork			fork;
	t_execve		execve;
}					t_data;

int					handle_error(t_data *d, char *error);
void				redirect_stdout_to_pipe(t_data *d);
void				init_data(t_data *d, char **argv, int argc);
void				create_pipe(t_data *d);
void				create_child_process(t_data *d);
void				open_input_file(t_data *d);
void				redirect_stdin_to_file_one(t_data *d);
void				execute_first_command(t_data *d);
void				open_output_file(t_data *d);
void				redirect_stdin_to_pipe(t_data *d);
void				redirect_stdout_to_file_two(t_data *d);
void				execute_second_command(t_data *d);
void				destroy_data(t_data *d);
void				get_full_cmds_paths(t_data *d);

static inline int	is_child_process(int id)
{
	return (id == 0);
}

#endif