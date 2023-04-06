/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:40:47 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 12:45:44 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
/*
dir
1 = LEFT
2 = UP
3 = RIGHT
0 = DOWN
*/
static int	is_this_a_rock(char c)
{
	if (c == '1')
		return (0);
	return (1);
}

static int	can_move(t_map *m, int dir)
{
	int	px;
	int	py;

	px = (*m).p_x;
	py = (*m).p_y;
	if (dir == 2)
		return (is_this_a_rock((*m).map[py -1][px]));
	if (dir == 3)
		return (is_this_a_rock((*m).map[py][px + 1]));
	if (dir == 0)
		return (is_this_a_rock((*m).map[py + 1][px]));
	if (dir == 1)
		return (is_this_a_rock((*m).map[py][px - 1]));
	return (0);
}

static void	colect(t_map *m, int dir)
{
	if (dir == 2)
	{
		if ((*m).map[(*m).p_y -1][(*m).p_x] == 'C')
			(*m).n_col--;
	}
	else if (dir == 3)
	{
		if ((*m).map[(*m).p_y][(*m).p_x + 1] == 'C')
			(*m).n_col--;
	}
	else if (dir == 0)
	{
		if ((*m).map[(*m).p_y +1][(*m).p_x] == 'C')
			(*m).n_col--;
	}
	else if (dir == 1)
	{
		if ((*m).map[(*m).p_y][(*m).p_x - 1] == 'C')
			(*m).n_col--;
	}
}

static void	move_player(t_map *m, int dir)
{
	if ((*m).map[(*m).p_y][(*m).p_x] == 'p')
		(*m).map[(*m).p_y][(*m).p_x] = 'E';
	else
		(*m).map[(*m).p_y][(*m).p_x] = '0';
	if (dir == 2)
		(*m).p_y--;
	else if (dir == 3)
		(*m).p_x++;
	else if (dir == 0)
		(*m).p_y++;
	else if (dir == 1)
		(*m).p_x--;
	if ((*m).map[(*m).p_y][(*m).p_x] == 'E' ||
			(*m).map[(*m).p_y][(*m).p_x] == 'e')
		(*m).map[(*m).p_y][(*m).p_x] = 'p';
	else
	(*m).map[(*m).p_y][(*m).p_x] = 'P';
}

/*
FUNCTION: move

Changes the player sprite direction and, if it can move:
1-Increses the number of moves.
2-Colects any colectibles in the way (and opens the exit door).
3-Puts the player on the right spot of the map.
4-Prints the number of movements to terminal.
5-If the player reaches the exit and the door is open, exits the game.
*/
void	move(t_game *g, t_map *m, int dir)
{
	(*g).dir = dir;
	if (can_move(m, dir))
	{
		(*g).mov++;
		colect(m, dir);
		move_player(m, dir);
		if ((*m).n_col == 0 && !(*m).open)
			open_door(m);
		if (((*m).open && (*m).map[(*m).p_y][(*m).p_x] == 'p'))
		{
			mlx_destroy_window((*g).mlx, (*g).win);
			ft_printf("YOU WIN!!!!!!!!!!!\n");
			exit_game(g);
		}
	}
}
