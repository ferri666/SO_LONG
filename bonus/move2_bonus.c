/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:44:34 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/28 13:30:40 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	open_door(t_map *m)
{
	int	dx;
	int	dy;

	(*m).open = 1;
	dx = find_exy((*m).map, (*m).max_y, 'x');
	dy = find_exy((*m).map, (*m).max_y, 'y');
	(*m).map[dy][dx] = 'e';
}
