/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:32:53 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/08 12:37:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	aux_free_arr(char **arr, void **aux);

void	ft_free_t_split(t_split *split)
{
	aux_free_arr(split->str_arr, (void **)split->str_arr);
	free(split);
	split = NULL;
}

static inline void	aux_free_arr(char **arr, void **aux)
{
	while (*arr)
	{
		free(*arr++);
		*arr = NULL;
	}
	free(aux);
	aux = NULL;
}
