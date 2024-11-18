/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:17:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/09 13:17:17 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_coord_y(int gun)
{
	if (gun == GUN_3)
		return (WEAPON_SPECIAL_Y);
	return (WEAPON_Y);
}

void	ft_draw_weapon(t_var *var, int gun)
{
	char	*image;
	t_coord	c;
	t_coord	t;
	int		color;

	c.y = init_coord_y(gun);
	t.y = 0;
	while (t.y < var->textures[gun].height)
	{
		t.x = 0;
		c.x = WEAPON_X;
		while (t.x < var->textures[gun].length)
		{
			image = var->textures[gun].addr + (t.y * var->textures[gun].line_l
					+ t.x * (var->textures[gun].bpp / 8));
			color = *(unsigned int *)image;
			if (color != 5992161)
				ft_pput(var, c.x, c.y, color);
			t.x++;
			c.x++;
		}
		t.y++;
		c.y++;
	}
}
