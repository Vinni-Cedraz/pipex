/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_for_execve.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:36:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/12 09:44:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			split_commands_from_their_args(t_data *d, char **argv);
static void			join_cmd_path_with_name(t_data *d);
static void			create_execve_strarrs(t_data *d);
static void			if_fullcmd_isgiven_byuser(t_data *d);

void	init_data_for_execve(t_data *d, char **argv, char **envp)
{
	d->file_descriptors = (t_fds){0};
	d->execve = (t_execve){0};
	d->args.file1 = argv[1];
	d->args.file2 = argv[4];
	d->args.envp = envp;
	split_commands_from_their_args(d, argv);
	if_fullcmd_isgiven_byuser(d);
	get_cmds_paths(d);
	join_cmd_path_with_name(d);
	create_execve_strarrs(d);
}

static inline void	split_commands_from_their_args(t_data *d, char **argv)
{
	d->split1 = ft_split(argv[2], ' ');
	d->execve.slash1 = ft_strrchr(d->split1->str_arr[0], '/');
	d->split2 = ft_split(argv[3], ' ');
	d->execve.slash2 = ft_strrchr(d->split2->str_arr[0], '/');
}

static inline void	if_fullcmd_isgiven_byuser(t_data *d)
{
	if (d->execve.slash1)
		ft_strlcpy(d->split1->str_arr[0], d->execve.slash1 + 1, 50);
	if (d->execve.slash2)
		ft_strlcpy(d->split2->str_arr[0], d->execve.slash2 + 1, 50);
}

static inline void	join_cmd_path_with_name(t_data *d)
{
	d->execve.full_cmd1 = ft_strjoin(d->args.cmd1_path, d->split1->str_arr[0]);
	d->execve.full_cmd2 = ft_strjoin(d->args.cmd2_path, d->split2->str_arr[0]);
}

static inline void	create_execve_strarrs(t_data *d)
{
	int	i;

	d->execve.str_arr1 = ft_calloc(sizeof(char *), d->split1->words + 1);
	i = -1;
	while (++i < (int)d->split1->words)
		d->execve.str_arr1[i] = ft_strdup(d->split1->str_arr[i]);
	d->execve.str_arr2 = ft_calloc(sizeof(char *), d->split2->words + 1);
	i = -1;
	while (++i < (int)d->split2->words)
		d->execve.str_arr2[i] = ft_strdup(d->split2->str_arr[i]);
}
