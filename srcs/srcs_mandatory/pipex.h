/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:52:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 13:33:27 by vcedraz-         ###   ########.fr       */
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
	char			*full_cmd1;
	char			*full_cmd2;
}					t_execve;

typedef struct s_pipe
{
	int				fd[2];
	int				input_fd;
	int				output_fd;
}					t_fds;

typedef struct s_data
{
	t_fds 			file_descriptors;
	t_split			*split;
	t_args			args;
	t_fork			fork;
	t_execve		execve;
}					t_data;

void				redirect_stdin_to_pipe(t_data *d);
void				redirect_stdout_to_file_two(t_data *d);
void				redirect_stdout_to_pipe(t_data *d);
void				redirect_stdin_to_file_one(t_data *d);
void				init_data(t_data *d, char **argv, int argc);
void				create_pipe(t_data *d);
void				create_child_process(t_data *d);
void				open_input_file(t_data *d);
void				open_output_file(t_data *d);
int					handle_error(t_data *d, char *error);

static inline void	get_full_cmds_paths(t_data *d)
{
	d->execve.full_cmd1 = ft_strjoin(ft_strdup("/usr/bin/"), d->args.cmd1);
	d->execve.full_cmd2 = ft_strjoin(ft_strdup("/usr/bin/"), d->args.cmd2);
}

static inline void	execute_first_command(t_data *d)
{
	execve(d->execve.full_cmd1, d->execve.cmd1_argv, NULL);
}

static inline void	execute_second_command(t_data *d)
{
	execve(d->execve.full_cmd2, d->execve.cmd2_argv, NULL);
}

static inline int	is_child_process(int id)
{
	return (id == 0);
}

static inline void	destroy_data(t_data *d)
{
	ft_free_arr(d->execve.cmd1_argv, (void **)d->execve.cmd1_argv);
	ft_free_arr(d->execve.cmd2_argv, (void **)d->execve.cmd2_argv);
	free(d->args.cmd2);
	free(d->args.cmd2_arg);
	free(d->split);
	free(d);
}

#endif
