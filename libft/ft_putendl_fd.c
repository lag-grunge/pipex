/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:37:59 by sdalton           #+#    #+#             */
/*   Updated: 2021/05/04 10:09:56 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Function name ft_putendl_fd 							*/
/*	Prototype void ft_putendl_fd(char *s, int fd); 			*/
/*	Turn in files - 										*/
/*	Parameters #1. The string to output. 					*/
/*	#2. The file descriptor on which to write. 				*/
/*	Return value None 										*/
/*	External functs. write 									*/
/*	Description Outputs the string ’s’ to the given file 	*/
/*	descriptor, followed by a newline. 						*/

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd(10, fd);
}
