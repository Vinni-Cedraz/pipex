/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_cmds_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:08:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/06 20:08:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_full_cmds_paths(t_data *d)
{
	d->pipe.full_cmd1 = ft_strjoin(ft_strdup("/usr/bin/"), d->args.cmd1);
	d->pipe.full_cmd2 = ft_strjoin(ft_strdup("/usr/bin/"), d->args.cmd2);
}
