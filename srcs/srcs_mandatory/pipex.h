/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:52:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/10 20:24:34 by vcedraz-         ###   ########.fr       */
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
	char 			**envp;
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
}					t_data;

typedef void		(*t_func)(t_data *);
int					is_valid_fd(int fd);
int					handle_error(t_data *d, char *error, t_func f);
int					is_child_process(int id);
int					is_parent(int id);
void				run_first_child_process(t_data *d);
void				run_second_child_process(t_data *d);
void				standard_free_function(t_data *d);
void				open_input_output_files(t_data *d);
int					create_first_child_process(t_data *d);
int					wait_and_create_second_child(t_data *d);
void				init_data_for_execve(t_data *d, char **argv, char **envp);

static inline void	free_error1(t_data *d)
{
	free(d);
}

static inline void	free_error2(t_data *d)
{
	free(d);
}

static inline void	free_error3(t_data *d)
{
	close(d->file_descriptors.input_fd);
	free(d);
}

static inline void	free_error4(t_data *d)
{
	close(d->file_descriptors.input_fd);
	close(d->file_descriptors.output_fd);
	close(d->file_descriptors.fd[READ_SIDE]);
	close(d->file_descriptors.fd[WRTE_SIDE]);
	free(d);
}

#endif
