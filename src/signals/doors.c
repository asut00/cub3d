/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:17:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/09 13:17:17 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	open_close_doors(t_var *var, int x, int y)
{
	if (var->map.map[y][x] == 'C')
		var->map.map[y][x] = 'O';
	else if (var->map.map[y][x] == 'O')
	{
		var->map.map[y][x] = 'C';
		if (is_collision(var->player_info.pos.x, var->player_info.pos.y, var))
			var->map.map[y][x] = 'O';
	}
}

static int	is_inbound(int x, int y, t_var *var)
{
	if (x < 0 || y < 0
		|| x >= var->map.max_col
		|| y >= var->map.max_row)
		return (0);
	return (1);
}

static void	manage_doors(t_var *var, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (is_inbound(x + i, y + j, var))
			{
				if (var->map.map[y + j][x + i] == 'C'
					|| var->map.map[y + j][x + i] == 'O')
					open_close_doors(var, x + i, y + j);
			}
			j++;
		}
		i++;
	}
}

void	try_opening_doors(t_var *var)
{
	int	x;
	int	y;

	x = var->player_info.pos.x;
	y = var->player_info.pos.y;
	manage_doors(var, x, y);
}
