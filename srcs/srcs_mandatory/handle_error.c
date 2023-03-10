/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:00:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/09 23:07:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_error(t_data *d, char *error, t_func custom_free_function_ptr)
{
	if (custom_free_function_ptr)
		(*custom_free_function_ptr)(d);
	perror(error);
	exit(-1);
}
