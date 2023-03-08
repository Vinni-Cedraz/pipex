/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:39:23 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/08 16:45:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

inline int	is_child_process(int id)
{
	return (id == 0);
}

inline int	is_parent(int id)
{
	return (id != 0);
}
