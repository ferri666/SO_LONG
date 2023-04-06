/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:14:03 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/28 12:11:52 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

/*
FUNCTION: find_pxy
This functions locates the player in a map and, depending on the mode
we gave it, returns the x or y of his position. In case of not locating
the player it returns -1, which should not be possible in this program
with any valid map.
*/
int	find_pxy(char **map, int n_lines, char mode)
{
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(map[0]);
	while (j < n_lines)
	{
		i = 0;
		while (i < len)
		{
			if (map[j][i] == 'P')
			{
				if (mode == 'x')
					return (i);
				if (mode == 'y')
					return (j);
			}
			i++;
		}
		j++;
	}
	return (-1);
}

/*
FUNCTION: number_of

It searches the map and returns the number of
instances on a given character.
*/
int	number_of(t_map *m, char c)
{
	size_t	i;
	int		j;
	size_t	len;
	int		ret;

	j = 0;
	ret = 0;
	len = (*m).max_x;
	while (j < (*m).max_y)
	{
		i = 0;
		while (i < len)
		{
			if ((*m).map[j][i] == c)
				ret++;
			i++;
		}
		j++;
	}
	return (ret);
}

/*
FUNCTION: find_exy
This functions locates the exit in a map and, depending on the mode
we gave it, returns the x or y of their position. In case of not locating
the exit it returns -1, which should not be possible in this program
with any valid map.
*/
int	find_exy(char **map, int n_lines, char mode)
{
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(map[0]);
	while (j < n_lines)
	{
		i = 0;
		while (i < len)
		{
			if (map[j][i] == 'E')
			{
				if (mode == 'x')
					return (i);
				if (mode == 'y')
					return (j);
			}
			i++;
		}
		j++;
	}
	return (-1);
}
