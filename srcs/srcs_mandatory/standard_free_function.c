/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_free_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:45:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/10 21:55:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void destroy_data(t_data *d);
static void close_fds(t_data *d);

void standard_free_function(t_data *d) {
  close_fds(d);
  destroy_data(d);
}

static inline void close_fds(t_data *d) {
  close(d->file_descriptors.input_fd);
  close(d->file_descriptors.output_fd);
  close(d->file_descriptors.fd[READ_SIDE]);
  close(d->file_descriptors.fd[WRTE_SIDE]);
}

static inline void destroy_data(t_data *d) {
  ft_free_arr(d->execve.str_arr1, (void **)d->execve.str_arr1);
  ft_free_arr(d->execve.str_arr2, (void **)d->execve.str_arr2);
  ft_free_t_split(d->split1);
  ft_free_t_split(d->split2);
  free(d->execve.full_cmd1);
  free(d->execve.full_cmd2);
  free(d->args.cmd1_path);
  free(d->args.cmd2_path);
  free(d);
}
