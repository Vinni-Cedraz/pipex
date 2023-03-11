/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:40:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/10 21:53:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void			get_cmd1_path(t_data *d, char **paths);
static void			get_cmd2_path(t_data *d, char **paths);

void	get_cmds_paths(t_data *d)
{
	char	**envp;
	t_split	*split;

	envp = d->args.envp;
	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	split = ft_split(*envp + 5, ':');
	get_cmd1_path(d, split->str_arr);
	get_cmd2_path(d, split->str_arr);
	ft_free_t_split(split);
}

static inline void	get_cmd1_path(t_data *d, char **paths)
{
	char	full_possible_name[99];

	while (*paths)
	{
		ft_strlcpy(full_possible_name, *paths, 99);
		ft_strlcat(full_possible_name, "/", 99);
		ft_strlcat(full_possible_name, d->split1->str_arr[0], 99);
		if (access(full_possible_name, F_OK | X_OK) == 0)
			break ;
		paths++;
	}
	d->args.cmd1_path = ft_strjoin(*paths, "/");
}

static inline void	get_cmd2_path(t_data *d, char **paths)
{
	char	full_possible_name[99];

	while (*paths)
	{
		ft_strlcpy(full_possible_name, *paths, 99);
		ft_strlcat(full_possible_name, "/", 99);
		ft_strlcat(full_possible_name, d->split2->str_arr[0], 99);
		if (access(full_possible_name, F_OK | X_OK) == 0)
			break ;
		paths++;
	}
	d->args.cmd2_path = ft_strjoin(*paths, "/");
}
