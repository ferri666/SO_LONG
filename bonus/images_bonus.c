/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:56:49 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/28 15:49:22 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	draw_col(t_game *g, int x, int y)
{
	int	i;

	i = (*g).mov % 20;
	if (i > 10)
		i = 20 - i;
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).col,
		x * 40 + 15, y * 40 + 10 + i);
}

void	draw_exit(t_game *g, int x, int y)
{
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).ext,
		x * 40 + 5, y * 40 + 5);
}

void	draw_a_wall(t_game *g, int x, int y)
{
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).obs,
		x * 40, y * 40);
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).obs,
		x * 40 + 20, y * 40);
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).obs,
		x * 40, y * 40 + 20);
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).obs,
		x * 40 + 20, y * 40 + 20);
}

void	draw_player(t_game *g, int x, int y)
{
	mlx_put_image_to_window((*g).mlx, (*g).win, (*g).pla[(*g).dir],
		x * 40 + 10, y * 40 + 10);
}
