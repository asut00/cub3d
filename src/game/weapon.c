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

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	is_light_gray(unsigned int color)
{
	int	r;
	int	g;
	int	b;
	int	threshold;
	int	delt_thresh;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	threshold = 100;
	delt_thresh = 34;
	return (ft_abs(r - g) < delt_thresh
		&& ft_abs(g - b) < delt_thresh
		&& ft_abs(b - r) < delt_thresh
		&& r > threshold && g > threshold && b > threshold);
}

void	ft_draw_weapon(t_var *var, int gun)
{
	char	*image;
	t_coord	c;
	t_coord	t;
	int		color;

	c.y = HANDS_Y;
	t.y = 0;
	while (t.y < var->textures[gun].height)
	{
		t.x = 0;
		c.x = HANDS_X;
		while (t.x < var->textures[gun].length)
		{
			image = var->textures[gun].addr + (t.y * var->textures[gun].line_l
					+ t.x * (var->textures[gun].bpp / 8));
			color = *(unsigned int *)image;
			if (color != 0xFFFFFF && !is_light_gray(color))
				ft_pput(var, c.x, c.y, color);
			t.x++;
			c.x++;
		}
		t.y++;
		c.y++;
	}
}
