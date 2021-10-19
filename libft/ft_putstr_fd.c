/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:33:07 by sdalton           #+#    #+#             */
/*   Updated: 2021/05/06 13:41:50 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Function name ft_putstr_fd 									*/
/*	Prototype void ft_putstr_fd(char *s, int fd); 				*/
/*	Turn in files - 											*/
/*	Parameters #1. The string to output. 						*/
/*	#2. The file descriptor on which to write. 					*/
/*	Return value None 											*/
/*	External functs. write 										*/
/*	Description Outputs the string ’s’ to the given file 		*/
/*	descriptor. 												*/

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}
