/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:17:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/09 13:17:17 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_player(t_var *var)
{
	int	i;
	int	j;

	i = -5;
	while (i < 5)
	{
		j = -5;
		while (j < 5)
		{
			if (i * i + j * j <= SIZE_PLAYER * SIZE_PLAYER)
				ft_pput(var, MINIMAP_CENTER + i, MINIMAP_CENTER + j,
					PLAYER_COLOR);
			j++;
		}
		i++;
	}
}

static int	chose_color(t_var *var, double x, double y)
{
	int	intx;
	int	inty;

	if (x < 0 || x >= var->map.max_col
		|| y < 0 || y >= var->map.max_row)
		return (OUT_OF_MAP);
	intx = x;
	inty = y;
	if (var->map.map[inty][intx] == ' ')
		return (OUT_OF_MAP);
	else if (var->map.map[inty][intx] == '1')
		return (WALL_COLOR);
	else if (var->map.map[inty][intx] == 'C'
		|| var->map.map[inty][intx] == 'O')
		return (DOORS_COLOR);
	return (EMPTY_COLOR);
}

void	zoom_minimap(t_var *var)
{
	if (var->zoom == 30)
		return ;
	var->zoom += 1;
}

void	dezoom_minimap(t_var *var)
{
	if (var->zoom == 5)
		return ;
	var->zoom -= 1;
}

void	ft_draw_minimap(t_var *var)
{
	int		i;
	int		j;
	t_vect	coord;
	int		color;

	i = -SIZE_MINIMAP;
	while (i < SIZE_MINIMAP)
	{
		j = -SIZE_MINIMAP;
		while (j < SIZE_MINIMAP)
		{
			if (i * i + j * j <= SIZE_MINIMAP * SIZE_MINIMAP)
			{
				coord.x = var->player_info.pos.x
					+ ((double)i / (double)var->zoom);
				coord.y = var->player_info.pos.y
					+ ((double)j / (double)var->zoom);
				color = chose_color(var, coord.x, coord.y);
				ft_pput(var, MINIMAP_CENTER + i, MINIMAP_CENTER + j, color);
			}
			j++;
		}
		i++;
	}
	ft_draw_player(var);
}
