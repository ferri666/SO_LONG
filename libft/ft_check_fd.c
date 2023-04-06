/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:54:46 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 12:44:29 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
FUNCTION: ft_check_fd
Checks if a file can be read, returning a 1 if it can
and a 0 if it doesn't.
*/
int	ft_check_fd(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		return (0);
	}
	close (fd);
	return (1);
}
