/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:00:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/12 09:44:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_error(t_data *d, char *error, t_func custom_free, int x)
{
	perror(error);
	(*custom_free)(d);
	exit(x);
}

void	cmd_one_is_nil(t_data *d)
{
	char	error_message[50];

	ft_strlcpy(error_message, "command not found: ", 20);
	ft_strlcat(error_message, d->split1->str_arr[0], 50);
	ft_putendl_fd(error_message, STDERR_FILENO);
	d->execve.cmd1_is_nil = 1;
}

void	cmd_two_is_nil(t_data *d)
{
	char	error_message[50];

	ft_strlcpy(error_message, "command not found: ", 20);
	ft_strlcat(error_message, d->split2->str_arr[0], 50);
	ft_putendl_fd(error_message, STDERR_FILENO);
	d->execve.cmd2_is_nil = 1;
}

void	custom_free2(t_data *d)
{
	close(d->file_descriptors.input_fd);
	close(d->file_descriptors.output_fd);
	free(d->args.cmd1_path);
	free(d->args.cmd2_path);
	ft_free_t_split(d->split1);
	ft_free_t_split(d->split2);
	free(d->execve.full_cmd1);
	free(d->execve.full_cmd2);
	ft_free_arr(d->execve.str_arr1, (void **)d->execve.str_arr1);
	ft_free_arr(d->execve.str_arr2, (void **)d->execve.str_arr2);
	free(d->paths);
	free(d);
}

void	custom_free3(t_data *d)
{
	close(d->file_descriptors.input_fd);
	close(d->file_descriptors.output_fd);
	close(d->file_descriptors.fd[READ_SIDE]);
	close(d->file_descriptors.fd[WRTE_SIDE]);
	free(d->args.cmd1_path);
	free(d->args.cmd2_path);
	ft_free_t_split(d->split1);
	ft_free_t_split(d->split2);
	free(d->execve.full_cmd1);
	free(d->execve.full_cmd2);
	ft_free_arr(d->execve.str_arr1, (void **)d->execve.str_arr1);
	ft_free_arr(d->execve.str_arr2, (void **)d->execve.str_arr2);
	free(d->paths);
	free(d);
}
