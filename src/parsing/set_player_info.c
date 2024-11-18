/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:40 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:47:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_var *var, double x, double y)
{
	var->player_info.dir.x = x;
	var->player_info.dir.y = y;
}

static void	set_ndir(t_var *var, double x, double y)
{
	var->player_info.ndir.x = x;
	var->player_info.ndir.y = y;
}

void	set_player_info(int row_nbr, int col_nbr, char dir, t_var *var)
{
	var->player_info.pos.x = col_nbr + 0.5;
	var->player_info.pos.y = row_nbr + 0.5;
	if (dir == 'N')
	{
		set_dir(var, 0, -1);
		set_ndir(var, 0.66, 0);
	}
	else if (dir == 'E')
	{
		set_dir(var, 1, 0);
		set_ndir(var, 0, 0.66);
	}
	else if (dir == 'S')
	{
		set_dir(var, 0, 1);
		set_ndir(var, -0.66, 0);
	}
	else if (dir == 'W')
	{
		set_dir(var, -1, 0);
		set_ndir(var, 0, -0.66);
	}
}
