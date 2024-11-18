/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:17:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/09 13:17:17 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pput(t_var *var, int x, int y, int color)
{
	char	*dst;

	if (x < W && y < H)
	{
		dst = var->data_addr + (y * var->line_length + x
				* (var->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_draw_ceiling(t_var *var, int x, int end)
{
	int	y;

	y = 0;
	while (y < end)
		ft_pput(var, x, y++, var->colors[C].value);
}

void	ft_draw_floor(t_var *var, int x, int start)
{
	int	y;

	y = start;
	while (y < H)
		ft_pput(var, x, y++, var->colors[F].value);
}
