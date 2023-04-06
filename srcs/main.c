/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:53:19 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 13:06:11 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
/*
void	leaks(void)
{
	system("leaks -q so_long");
}
*/

int	main(int ac, char **av)
{
	t_map	r_map;
	t_map	f_map;

	check_arg(ac, av);
	r_map.max_y = ft_nlines(av[1]);
	r_map.map = dunk(av[1], r_map.max_y);
	f_map.max_y = r_map.max_y;
	f_map.map = dunk(av[1], r_map.max_y);
	if (!validate(r_map))
		map_error(r_map, "Error\nMapa no rectangular\n");
	if (!borders(r_map))
		map_error(r_map, "Error\nMapa no cerrado correctamente\n");
	if (!num_char(r_map))
		map_error(r_map, "Error\nNúmero incorrecto de carácteres\n");
	if (!val_char(r_map))
		map_error(r_map, "Error\nMapa con Carácter Inválido\n");
	init_map(&r_map);
	init_map(&f_map);
	if (!check_flood(&f_map))
		map_error(r_map, "Error\nMapa Imposible de Resolver\n");
	start_game(&r_map);
}
