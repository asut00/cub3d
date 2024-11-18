/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:30:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/22 12:30:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_x_on_wall(t_ray *ray, t_var *var)
{
	if (ray->side == 0)
		ray->wall_x = var->player_info.pos.y + ray->wall_dist * ray->raydir.y;
	else
		ray->wall_x = var->player_info.pos.x + ray->wall_dist * ray->raydir.x;
	ray->wall_x = ray->wall_x - (int)ray->wall_x;
}

static void	get_text(t_ray *ray, t_var *var)
{
	if (ray->hit == 'C')
	{
		ray->texture = &var->textures[DOOR];
		return ;
	}
	else if (ray->side == 0)
	{
		if (ray->raydir.x < 0)
			ray->texture = &var->textures[EA];
		else if (ray->raydir.x > 0)
			ray->texture = &var->textures[WE];
	}
	else if (ray->side == 1)
	{
		if (ray->raydir.y > 0)
			ray->texture = &var->textures[NO];
		else if (ray->raydir.y < 0)
			ray->texture = &var->textures[SO];
	}
}

static void	get_x_on_text(t_ray *ray)
{
	ray->text_x = ray->wall_x * (double)ray->texture->length;
	if (ray->side == 0 && ray->raydir.x > 0)
		ray->text_x = ray->texture->length - ray->text_x - 1;
	if (ray->side == 1 && ray->raydir.y < 0)
		ray->text_x = ray->texture->length - ray->text_x - 1;
}

void	get_ver_line(t_ray *ray, t_var *var, int x)
{
	double	step;
	char	*image;
	double	text_pos;
	int		y;
	int		text_y;

	get_x_on_wall(ray, var);
	get_text(ray, var);
	get_x_on_text(ray);
	step = (double)(ray->texture->length) / (double)ray->line_height;
	text_pos = (ray->start - H / 2 + ray->line_height / 2) * step;
	ft_draw_ceiling(var, x, ray->start);
	y = ray->start;
	while (y < ray->end)
	{
		text_y = text_pos;
		text_pos += step;
		image = ray->texture->addr + (text_y * ray->texture->line_l
				+ ray->text_x * (ray->texture->bpp / 8));
		ray->color = *(unsigned int *)image;
		if (ray->side == 1)
			ray->color = (ray->color & 0xfefefe) >> 1;
		ft_pput(var, x, y++, ray->color);
	}
	ft_draw_floor(var, x, ray->end);
}
