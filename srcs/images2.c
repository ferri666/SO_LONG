/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:15:28 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/28 13:28:39 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	draw_a_thing(t_game *g, int x, int y, char c)
{
	if (c == '1')
		draw_a_wall(g, x, y);
	if (c == 'C')
		draw_col(g, x, y);
	if (c == 'P')
		draw_player(g, x, y);
	if (c == 'E')
		draw_trap(g, x, y);
	if (c == 'p')
	{
		draw_trap(g, x, y);
		draw_player(g, x, y);
	}
	if (c == 'e')
		draw_exit(g, x, y);
}

void	draw_face(t_game *g)
{
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).face,
		120, (*g).map->max_y * 40);
}

void	draw_trap(t_game *g, int x, int y)
{
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).tra,
		x * 40 + 5, y * 40 + 5);
}

void	draw_floor(t_game *g, t_map *m)
{
	int	i_x;
	int	i_y;

	i_y = 0;
	while (i_y < (*m).max_y + 1)
	{
		i_x = 0;
		while (i_x < (*m).max_x + 1)
		{
			mlx_put_image_to_window((*g).mlx, (*g).win, (*g).flo,
				i_x * 40, i_y * 40);
			mlx_put_image_to_window((*g).mlx, (*g).win, (*g).flo,
				i_x * 40, (i_y * 40) + 20);
			mlx_put_image_to_window((*g).mlx, (*g).win, (*g).flo,
				(i_x * 40) + 20, (i_y * 40) + 20);
			mlx_put_image_to_window((*g).mlx, (*g).win, (*g).flo,
				(i_x * 40) + 20, i_y * 40);
			i_x++;
		}
		i_y++;
	}
}

void	draw_map(t_game *g, t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (*m).max_y)
	{
		i = 0;
		while (i < (*m).max_x)
		{
			draw_a_thing(g, i, j, (*m).map[j][i]);
			i++;
		}
		j++;
	}
}
