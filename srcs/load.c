/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:36:57 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/28 15:46:03 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	load_images3(t_game *g)
{
	int		play;
	int		tile;

	tile = 16;
	play = 40;
	if (ft_check_fd("textures/FACE.xpm"))
		(*g).face = mlx_xpm_file_to_image((*g).mlx, "textures/FACE.xpm",
				&play, &play);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
	if (ft_check_fd("textures/TRAP.xpm"))
		(*g).tra = mlx_xpm_file_to_image((*g).mlx, "textures/TRAP.xpm",
				&play, &play);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
}

void	load_images2(t_game *g)
{
	int		play;

	play = 40;
	if (ft_check_fd("textures/SCI.xpm"))
		(*g).pla[0] = mlx_xpm_file_to_image((*g).mlx, "textures/SCI.xpm",
				&play, &play);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
	if (ft_check_fd("textures/SCI2.xpm"))
		(*g).pla[1] = mlx_xpm_file_to_image((*g).mlx, "textures/SCI2.xpm",
				&play, &play);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
	if (ft_check_fd("textures/SCI3.xpm"))
		(*g).pla[2] = mlx_xpm_file_to_image((*g).mlx, "textures/SCI3.xpm",
				&play, &play);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
	if (ft_check_fd("textures/SCI4.xpm"))
		(*g).pla[3] = mlx_xpm_file_to_image((*g).mlx, "textures/SCI4.xpm",
				&play, &play);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
}

void	load_images(t_game *g)
{
	int		tile;

	tile = 16;
	if (ft_check_fd("textures/WALL.xpm"))
		(*g).obs = mlx_xpm_file_to_image((*g).mlx, "textures/WALL.xpm",
				&tile, &tile);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
	if (ft_check_fd("textures/FLOOR.xpm"))
		(*g).flo = mlx_xpm_file_to_image((*g).mlx, "textures/FLOOR.xpm",
				&tile, &tile);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
	if (ft_check_fd("textures/ESC.xpm"))
		(*g).ext = mlx_xpm_file_to_image((*g).mlx, "textures/ESC.xpm",
				&tile, &tile);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
	if (ft_check_fd("textures/POT2.xpm"))
		(*g).col = mlx_xpm_file_to_image((*g).mlx, "textures/POT2.xpm",
				&tile, &tile);
	else
		dmap_error((*g).map->map, "Error:\nMissing texture\n");
}
