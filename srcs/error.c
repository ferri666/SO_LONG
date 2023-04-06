/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:19:16 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 12:46:44 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

/*
FUNCTION: map_error, dmap_error
Both functions free the matrix of the map, displays an error 
message and exits the program.
The only difference is in the type of argument they recibed.
*/
void	map_error(t_map t_map, char *str)
{
	ft_putstr_fd(str, 2);
	ft_free_matrix((void **)t_map.map);
	exit(-1);
}

void	dmap_error(char	**map, char *str)
{
	ft_putstr_fd(str, 2);
	ft_free_matrix((void **)map);
	exit(-1);
}
