/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:40 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:47:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal_check(char **map, t_var *var)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			while (map[row][col] == ' ')
				col++;
			if (map[row][col] && map[row][col] != '1')
				border_error(var);
			while (map[row][col] && map[row][col] != ' ')
				col++;
			if (map[row][col - 1] != ' ' && map[row][col - 1] != '1')
				border_error(var);
		}
		row++;
	}
}

static void	vertical_check(char **map, t_var *var)
{
	int	row;
	int	col;

	col = 0;
	row = 0;
	while (map[row][col])
	{
		while (map[row])
		{
			while (map[row] && map[row][col] == ' ')
				row++;
			if (map[row] && map[row][col] != '1')
				border_error(var);
			while (map[row] && map[row][col] != ' ')
				row++;
			if (map[row - 1][col] != ' ' && map[row - 1][col] != '1')
				border_error(var);
		}
		row = 0;
		col++;
	}
}

static int	is_empty_char(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == 'O' || c == ' ');
}

static void	check_line_component(char *line, int line_nbr, t_var *var)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_empty_char(line[i]) && line[i] != '1'
			&& line[i] != 'C')
			char_error(line[i], var);
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
		{
			if (var->player++ == 1)
				map_config_error(var);
			set_player_info(line_nbr, i, line[i], var);
		}
		i++;
	}
}

void	check_map_component(t_var *var)
{
	int		i;
	char	**map;

	map = var->map.map;
	var->player = 0;
	i = 0;
	while (map[i])
	{
		check_line_component(map[i], i, var);
		i++;
	}
	if (var->player == 0)
		map_config_error(var);
	horizontal_check(map, var);
	vertical_check(map, var);
}
