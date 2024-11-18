/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:54:22 by asuteau           #+#    #+#             */
/*   Updated: 2024/09/10 17:54:23 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_collision(double x, double y, t_var *var)
{
	int		intx;
	int		inty;
	char	**map;

	map = var->map.map;
	intx = x + HITBOX;
	inty = y + HITBOX;
	if (map[inty][intx] == '1' || map[inty][intx] == 'C')
		return (1);
	intx = x - HITBOX;
	if (map[inty][intx] == '1' || map[inty][intx] == 'C')
		return (1);
	inty = y - HITBOX;
	if (map[inty][intx] == '1' || map[inty][intx] == 'C')
		return (1);
	intx = x + HITBOX;
	if (map[inty][intx] == '1' || map[inty][intx] == 'C')
		return (1);
	return (0);
}

void	move_straight(t_var *var, t_move move)
{
	double	new_x;
	double	new_y;
	double	x;
	double	y;

	x = var->player_info.pos.x;
	y = var->player_info.pos.y;
	new_x = x + move * (var->player_info.dir.x * MOVE);
	new_y = y + move * (var->player_info.dir.y * MOVE);
	if (!is_collision(new_x, new_y, var))
	{
		var->player_info.pos.x = new_x;
		var->player_info.pos.y = new_y;
	}
	else if (!is_collision(new_x, y, var))
		var->player_info.pos.x = new_x;
	else if (!is_collision(x, new_y, var))
		var->player_info.pos.y = new_y;
}

void	straf(t_var *var, t_move move)
{
	double	new_x;
	double	new_y;
	double	x;
	double	y;

	x = var->player_info.pos.x;
	y = var->player_info.pos.y;
	new_x = x + move * (var->player_info.ndir.x * MOVE);
	new_y = y + move * (var->player_info.ndir.y * MOVE);
	if (!is_collision(new_x, new_y, var))
	{
		var->player_info.pos.x = new_x;
		var->player_info.pos.y = new_y;
	}
	else if (!is_collision(new_x, y, var))
		var->player_info.pos.x = new_x;
	else if (!is_collision(x, new_y, var))
		var->player_info.pos.y = new_y;
}

void	rotate(t_var *var, double angle)
{
	double	olddirx;
	double	oldndirx;

	olddirx = var->player_info.dir.x;
	oldndirx = var->player_info.ndir.x;
	var->player_info.dir.x *= cos(angle);
	var->player_info.dir.x -= var->player_info.dir.y * sin(angle);
	var->player_info.dir.y *= cos(angle);
	var->player_info.dir.y += olddirx * sin(angle);
	var->player_info.ndir.x *= cos(angle);
	var->player_info.ndir.x -= var->player_info.ndir.y * sin(angle);
	var->player_info.ndir.y *= cos(angle);
	var->player_info.ndir.y += oldndirx * sin(angle);
}
