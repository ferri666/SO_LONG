/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:25:02 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/28 13:30:22 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

/*
FUNCTION: check_type
Checks that the argument passed it's a file ".ber"
*/
int	check_type(char *str)
{
	char	*type;

	type = ft_strrchr(str, '.');
	if (!type)
		return (0);
	if (ft_strncmp(type, ".ber", 5) != 0)
		return (0);
	return (1);
}

/*
FUNCTION: dunk
Reads all the lines from the file and returns an array with the map.
*/
char	**dunk(char *str, int n_lines)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	fd = open (str, O_RDONLY);
	map = ft_calloc(n_lines + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < n_lines)
	{
		line = get_next_line(fd);
		if (!line)
			dmap_error(map, "Error\nEmpty line or Memory problem\n");
		if (i == n_lines - 1)
			map[i] = ft_substr(line, 0, ft_strlen(line));
		else
			map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		i++;
		free(line);
	}
	map[i] = 0;
	close (fd);
	return (map);
}

/*
FUNCTION: validate
Checks that the map is square and doesn't have empty lines.
*/
int	validate(t_map t_map)
{
	char	**map;
	char	*line;
	int		n_lines;
	size_t	len;
	int		i;

	i = 0;
	map = t_map.map;
	n_lines = t_map.max_y;
	while (i < n_lines)
	{
		line = map[i];
		if (i == 0)
			len = ft_strlen(line);
		if (len != ft_strlen(line))
			return (0);
		i++;
	}
	return (1);
}

/*
FUNCTION: check_arg
Checks that the arguments are valid, before verifing the map
*/
void	check_arg(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nNúmero de Argumentos Inválido\n", 2);
		exit (-1);
	}
	if (!check_type(av[1]))
	{
		ft_putstr_fd("Error\nArchivo no válido\n", 2);
		exit (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nMapa no encontrado\n", 2);
		exit (-1);
	}
	close(fd);
}

/*
FUNCTION: init_map
Initializes all the remaining variables of the structure s_map.
*/
void	init_map(t_map *t_map)
{
	(*t_map).max_x = ft_strlen((*t_map).map[0]);
	(*t_map).n_col = number_of(t_map, 'C');
	(*t_map).p_x = find_pxy((*t_map).map, (*t_map).max_y, 'x');
	(*t_map).p_y = find_pxy((*t_map).map, (*t_map).max_y, 'y');
	(*t_map).open = 0;
}
