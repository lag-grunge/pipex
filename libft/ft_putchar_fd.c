/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:21:19 by sdalton           #+#    #+#             */
/*   Updated: 2021/05/04 11:26:05 by sdalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Function name ft_putchar_fd 								*/
/*	Prototype void ft_putchar_fd(char c, int fd); 				*/
/*	Turn in files - 											*/
/*	Parameters #1. The character to output. 					*/
/*	#2. The file descriptor on which to write. 					*/
/*	Return value None 											*/
/*	External functs. write 										*/
/*	Description Outputs the character ’c’ to the given file 	*/
/*	descriptor. 												*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
