/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:25:05 by sdalton           #+#    #+#             */
/*   Updated: 2021/04/28 13:51:07 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** The calloc() function allocates memory for an array of nmemb elements 
* 	of size bytes each 
* and returns a pointer to the allocated memory. The memory is set to zero. 
* If nmemb or size is 0, then calloc() returns either NULL, or a unique 
* pointer value 
* that can later be successfully passed to free().
**/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*memory;

	bytes = nmemb * size;
	if (bytes)
	{
		memory = malloc(bytes);
		if (memory)
		{
			ft_bzero(memory, bytes);
			return (memory);
		}
		return (NULL);
	}
	return (malloc (1));
}
