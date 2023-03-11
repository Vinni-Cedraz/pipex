/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:52:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/11 16:21:30 by vcedraz-         ###   ########.fr       */
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
	char			**envp;
	char			*cmd1_path;
	char			*cmd2_path;
	int				argc;
}					t_args;

typedef struct s_execve
{
	char			**str_arr1;
	char			**str_arr2;
	char			*full_cmd1;
	char			*full_cmd2;
}					t_execve;

typedef struct s_fds
{
	int				input_fd;
	int				output_fd;
	int				fd[2];
}					t_fds;

typedef struct s_data
{
	t_fds			file_descriptors;
	t_split			*split1;
	t_split			*split2;
	t_args			args;
	t_execve		execve;
	char			**paths;
}					t_data;

typedef void		(*t_func)(t_data *);
int					is_valid_fd(int fd);
int					is_child_process(int id);
int					is_parent(int id);
void				run_first_child_process(t_data *d);
void				run_second_child_process(t_data *d);
void				standard_free_function(t_data *d);
void				open_input_output_files(t_data *d);
int					create_first_child_process(t_data *d);
int					wait_and_create_second_child(t_data *d);
void				init_data_for_execve(t_data *d, char **argv, char **envp);
int					handle_error(t_data *d, char *err, t_func free_err, int x);
void				get_cmds_paths(t_data *d);

static inline void	free_error1(t_data *d)
{
	ft_putstr_fd(d->split1->str_arr[0], 2);
	ft_free_t_split(d->split1);
	ft_free_t_split(d->split2);
	free(d->paths);
	free(d);
}

static inline void	free_error1_alt(t_data *d)
{
	ft_putstr_fd(d->split2->str_arr[0], 2);
	free(d->args.cmd1_path);
	ft_free_t_split(d->split1);
	ft_free_t_split(d->split2);
	free(d->paths);
	free(d);
}

static inline void	free_error2(t_data *d)
{
	close(d->file_descriptors.input_fd);
	close(d->file_descriptors.output_fd);
	free(d->args.cmd1_path);
	free(d->args.cmd2_path);
	ft_free_t_split(d->split1);
	ft_free_t_split(d->split2);
	free(d->execve.full_cmd1);
	free(d->execve.full_cmd2);
	ft_free_arr(d->execve.str_arr1, (void **)d->execve.str_arr1);
	ft_free_arr(d->execve.str_arr2, (void **)d->execve.str_arr2);
	free(d->paths);
	free(d);
}

static inline void	free_error3(t_data *d)
{
	close(d->file_descriptors.input_fd);
	close(d->file_descriptors.output_fd);
	close(d->file_descriptors.fd[READ_SIDE]);
	close(d->file_descriptors.fd[WRTE_SIDE]);
	free(d->args.cmd1_path);
	free(d->args.cmd2_path);
	ft_free_t_split(d->split1);
	ft_free_t_split(d->split2);
	free(d->execve.full_cmd1);
	free(d->execve.full_cmd2);
	ft_free_arr(d->execve.str_arr1, (void **)d->execve.str_arr1);
	ft_free_arr(d->execve.str_arr2, (void **)d->execve.str_arr2);
	free(d->paths);
	free(d);
}

#endif
