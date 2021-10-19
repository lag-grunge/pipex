/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:00:31 by sdalton           #+#    #+#             */
/*   Updated: 2021/04/26 12:08:08 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*		The bzero() function erases the data in the n bytes of the memory	*/
/*       	starting at the location pointed to by s, by writing zeros 		*/	
/*        	(bytes	containing '\0') to that area.							*/
/*		Return value is none.												*/

void	ft_bzero(void *b, size_t n)
{
	ft_memset(b, 0, n);
}
