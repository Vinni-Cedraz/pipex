/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_parent_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:45:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/07 16:35:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	continue_parent_process(t_data *d)
{
	wait(0);
	run_second_child_process(d);
	wait(0);
	close_fds(d);
	destroy_data(d);
}
