/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:40:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/12 12:25:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			get_cmd1_path(t_data *d);
static void			get_cmd2_path(t_data *d);

void	get_cmds_paths(t_data *d)
{
	char	**envp;

	envp = d->args.envp;
	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	d->paths = ft_split_envp(*envp + 5, ':');
	get_cmd1_path(d);
	get_cmd2_path(d);
}

static inline void	get_cmd1_path(t_data *d)
{
	char	full_possible_name[99];
	char	**paths;

	paths = d->paths;
	while (*paths)
	{
		ft_strlcpy(full_possible_name, *paths, 99);
		ft_strlcat(full_possible_name, "/", 99);
		ft_strlcat(full_possible_name, d->split1->str_arr[0], 99);
		if (access(full_possible_name, F_OK | X_OK) == 0)
			break ;
		paths++;
	}
	if (!*paths)
	{
		printf("%s\n", d->split1->str_arr[0]);
		cmd_one_is_nil(d);
	}
	d->args.cmd1_path = ft_strjoin(*paths, "/");
}

static inline void	get_cmd2_path(t_data *d)
{
	char	full_possible_name[99];
	char	**paths;

	paths = d->paths;
	while (*paths)
	{
		ft_strlcpy(full_possible_name, *paths, 99);
		ft_strlcat(full_possible_name, "/", 99);
		ft_strlcat(full_possible_name, d->split2->str_arr[0], 99);
		if (access(full_possible_name, F_OK | X_OK) == 0)
			break ;
		paths++;
	}
	if (!*paths)
		cmd_two_is_nil(d);
	d->args.cmd2_path = ft_strjoin(*paths, "/");
}
