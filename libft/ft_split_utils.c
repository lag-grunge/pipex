/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:14:25 by sdalton           #+#    #+#             */
/*   Updated: 2021/10/10 19:07:59 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_spllen(char **spl)
{
	size_t	i;

	i = 0;
	while (*spl++)
		i++;
	return (i);
}

void	clean_split(char **split, unsigned int i)
{
	while (i > 0)
	{
		free(split[i - 1]);
		i--;
	}
	free(split);
}
