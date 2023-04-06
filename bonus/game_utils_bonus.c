/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:06:59 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/28 13:29:56 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

/*
FUNCTION exit game
Used to terminate the program and free the map,
while also displaying a message.
*/
void	exit_game(t_game *g)
{
	ft_free_matrix((void **)(*g).map->map);
	ft_printf("BYE-BYE!\n");
	exit (0);
}
