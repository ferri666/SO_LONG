/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:22 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 12:45:00 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
/*
void	display_map(char **map, int n_lines)
{
	int	i;

	i = 0;
	while (i < n_lines)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}
*/

static int	can_flo(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	return (1);
}

static void	flood(char **map, int px, int py, int n_lines)
{
	map[py][px] = 'F';
	if (can_flo(map, px + 1, py))
		flood(map, px + 1, py, n_lines);
	if (can_flo(map, px, py + 1))
		flood(map, px, py + 1, n_lines);
	if (can_flo(map, px - 1, py))
		flood(map, px - 1, py, n_lines);
	if (can_flo(map, px, py - 1))
		flood(map, px, py - 1, n_lines);
}

int	check_flood(t_map *m)
{
	flood((*m).map, (*m).p_x, (*m).p_y, (*m).max_y);
	if (find_exy((*m).map, (*m).max_y, 'x') >= 0 || number_of(m, 'C') != 0)
	{
		ft_free_matrix((void **)(*m).map);
		return (0);
	}
	ft_free_matrix((void **)(*m).map);
	return (1);
}
