/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:52:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/12 16:39:55 by vcedraz-         ###   ########.fr       */
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
	char		*file1;
	char		*file2;
	char		**envp;
	char		*cmd1_path;
	char		*cmd2_path;
	int			argc;
}				t_args;

typedef struct s_execve
{
	char		**str_arr1;
	char		**str_arr2;
	char		*full_cmd1;
	char		*full_cmd2;
	char		*slash1;
	char		*slash2;
	short		cmd1_is_nil;
	short		cmd2_is_nil;
}				t_execve;

typedef struct s_fds
{
	int			input_fd;
	int			output_fd;
	int			fd[2];
}				t_fds;

typedef struct s_data
{
	t_fds		file_descriptors;
	t_split		*split1;
	t_split		*split2;
	t_args		args;
	t_execve	execve;
	char		**paths;
}				t_data;

typedef void	(*t_func)(t_data *);
int				is_valid_fd(int fd);
int				is_child_process(int id);
int				is_parent(int id);
void			run_first_child_process(t_data *d);
void			run_second_child_process(t_data *d);
void			standard_free_function(t_data *d);
void			open_input_output_files(t_data *d);
int				create_first_child_process(t_data *d);
int				create_second_child(t_data *d);
void			init_data_for_execve(t_data *d, char **argv, char **envp);
int				handle_error(t_data *d, char *err, t_func free_err, int x);
void			cmd_one_is_nil(t_data *d);
void			cmd_two_is_nil(t_data *d);
void			get_cmds_paths(t_data *d);
void			custom_free2(t_data *d);
void			custom_free3(t_data *d);

#endif
