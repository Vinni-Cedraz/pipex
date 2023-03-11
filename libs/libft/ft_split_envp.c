/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:11:51 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/11 15:39:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*next_whitespace(char *str, char c);
static char	*next_valid_char(char *str, char c);

char	**ft_split_envp(char *str, char c)
{
	int		index;
	t_split	ptr;

	index = 0;
	ptr.words = ft_word_counter(str, c);
	ptr.str_arr = malloc(sizeof(char *) * (ptr.words + 1));
	ptr.str_arr[ptr.words] = NULL;
	while (*str && index < (int)ptr.words)
	{
		str = next_valid_char(str, c);
		if (*str)
		{
			ptr.str_arr[index++] = str;
			str = next_whitespace(str, c);
			*str++ = '\0';
		}
	}
	return (ptr.str_arr);
}

static char	*next_whitespace(char *str, char c)
{
	while (*str != '\0' && *str != c)
		str++;
	return (str);
}

static char	*next_valid_char(char *str, char c)
{
	while (*str == c)
		str++;
	return (str);
}
