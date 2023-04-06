/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:35:32 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 12:48:29 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/stat.h>

typedef struct s_map {
	char	**map;
	int		max_x;
	int		max_y;
	int		n_col;
	int		p_x;
	int		p_y;
	int		open;
}				t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*col;
	void	*pla[4];
	void	*obs;
	void	*flo;
	void	*ext;
	void	*face;
	void	*tra;
	void	*box;
	t_map	*map;
	int		mov;
	int		dir;
}				t_game;

//CONTROL
void	start_game(t_map *map);
void	init_map(t_map *t_map);
void	check_arg(int ac, char **av);
char	**dunk(char *str, int n_lines);
int		validate(t_map t_map);
int		check_flood(t_map *m);
void	load_images(t_game *g);
void	load_images2(t_game *g);
void	load_images3(t_game *g);
void	exit_game(t_game *g);
//DRAW IMAGES
void	draw_floor(t_game *g, t_map *m);
void	draw_col(t_game *g, int x, int y);
void	draw_a_wall(t_game *g, int x, int y);
void	draw_exit(t_game *g, int x, int y);
void	draw_player(t_game *g, int x, int y);
void	draw_map(t_game *g, t_map *m);
void	draw_trap(t_game *g, int x, int y);
void	draw_face(t_game *g);
//ERROR_MAP
void	map_error(t_map t_map, char *str);
void	dmap_error(char	**map, char *str);
//MAP UTILS
int		borders(t_map t_map);
int		val_char(t_map t_map);
int		num_char(t_map t_map);
int		find_pxy(char **map, int n_lines, char mode);
int		find_exy(char **map, int n_lines, char mode);
int		number_of(t_map *m, char c);
//MOVEMENT
void	move(t_game *g, t_map *map, int dir);
void	open_door(t_map *m);

#endif