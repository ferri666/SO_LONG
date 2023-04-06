/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:43:06 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 12:58:43 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

static int	key_move(int keycode, t_game *game)
{
	if (keycode == 0 || keycode == 123)
		move(game, (*game).map, 1);
	if (keycode == 13 || keycode == 126)
		move(game, (*game).map, 2);
	if (keycode == 1 || keycode == 125)
		move(game, (*game).map, 0);
	if (keycode == 2 || keycode == 124)
		move(game, (*game).map, 3);
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit_game(game);
	}
	return (1);
}

static int	render(t_game	*g)
{
	char	*mov;

	mov = ft_itoa((*g).mov);
	mlx_clear_window((*g).mlx, (*g).win);
	draw_floor(g, (*g).map);
	draw_map(g, (*g).map);
	mlx_string_put((*g).mlx, (*g).win, 10, (*g).map->max_y * 40 + 10,
		0x00000000, "Moves:");
	mlx_string_put((*g).mlx, (*g).win, 70, (*g).map->max_y * 40 + 10,
		0x00000000, mov);
	mlx_string_put((*g).mlx, (*g).win, 9, (*g).map->max_y * 40 + 11,
		0x00FF0000, "Moves:");
	mlx_string_put((*g).mlx, (*g).win, 69, (*g).map->max_y * 40 + 11,
		0x00FF0000, mov);
	draw_face(g);
	mlx_string_put((*g).mlx, (*g).win, 150, (*g).map->max_y * 40 + 12,
		0x00000000, " x 3");
	mlx_string_put((*g).mlx, (*g).win, 149, (*g).map->max_y * 40 + 11,
		0x00FFFF00, " x 3");
	free(mov);
	return (1);
}

static int	mlx_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit_game(game);
	return (0);
}

static void	init_game(t_game *g, t_map *map)
{
	int		x;
	int		y;

	(*g).mlx = mlx_init();
	load_images(g);
	load_images2(g);
	load_images3(g);
	x = map->max_x * 40;
	y = map->max_y * 40;
	(*g).mov = 0;
	(*g).dir = 0;
	(*g).win = mlx_new_window((*g).mlx, x, y + 45, "LAB-RINTH");
}

void	start_game(t_map *map)
{
	t_game	game;

	game.map = map;
	init_game(&game, game.map);
	mlx_hook(game.win, 17, 0, mlx_quit, &game);
	mlx_key_hook(game.win, key_move, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
}
