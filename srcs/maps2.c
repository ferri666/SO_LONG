/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:09:54 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/30 12:38:02 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

/*
FUNCTION: borders

Checks that the map is closed accordingly.
*/
int	borders(t_map	t_map)
{
	int		i;
	size_t	j;
	char	**map;
	int		n_lines;

	map = t_map.map;
	n_lines = t_map.max_y;
	i = 0;
	while (i < n_lines)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (i == 0 || j == 0 || i == n_lines -1
				|| j == ft_strlen(map[i]) - 1)
				if (map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
FUNCTION: val_char
Checks that the map has a valid number of each character:
-Must have at least 1 Collectible
-Only 1 Exit
-Only 1 Player
*/
int	num_char(t_map t_map)
{
	int		i;
	int		num[3];
	char	**map;
	int		n_lines;

	map = t_map.map;
	n_lines = t_map.max_y;
	i = 0;
	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	while (i < n_lines)
	{
		num[0] += ft_countchr(map[i], 'P');
		num[1] += ft_countchr(map[i], 'C');
		num[2] += ft_countchr(map[i], 'E');
		i++;
	}
	if (num[0] != 1 || num[1] < 1 || num[2] != 1)
		return (0);
	return (1);
}

/*
FUNCTION: val_char
Checks that all the characters on a map are valid.
'E' 'P' 'C' '1' '0' are the only valid characters.
*/
int	val_char(t_map t_map)
{
	int		i;
	size_t	j;
	size_t	len;
	char	**map;
	int		n_lines;

	map = t_map.map;
	n_lines = t_map.max_y;
	i = 0;
	len = ft_strlen(map[0]);
	while (i < n_lines)
	{
		j = 0;
		while (j < len)
		{
			if (map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
