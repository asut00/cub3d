/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:30:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/22 12:30:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	init_ray_2(t_ray *ray, t_vect pos)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->dist_side.x = (pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->dist_side.x = (ray->map.x + 1.0 - pos.x) * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->dist_side.y = (pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->dist_side.y = (ray->map.y + 1.0 - pos.y) * ray->deltadist.y;
	}
}

static void	init_ray(t_ray *ray, t_var *var, int x)
{
	ray->map.x = var->player_info.pos.x;
	ray->map.y = var->player_info.pos.y;
	ray->camx = (2 * x / (double)W) - 1;
	ray->raydir.x = var->player_info.dir.x;
	ray->raydir.x += var->player_info.ndir.x * ray->camx;
	ray->raydir.y = var->player_info.dir.y;
	ray->raydir.y += var->player_info.ndir.y * ray->camx;
	ray->deltadist.x = 1e30;
	ray->deltadist.y = 1e30;
	if (ray->raydir.x)
		ray->deltadist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.y)
		ray->deltadist.y = fabs(1 / ray->raydir.y);
	init_ray_2(ray, var->player_info.pos);
}

static void	calculate_dist(t_ray *ray, t_var *var)
{
	while (ray->hit == 0)
	{
		if (ray->dist_side.x < ray->dist_side.y)
		{
			ray->dist_side.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->dist_side.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (var->map.map[ray->map.y][ray->map.x] == '1'
		|| var->map.map[ray->map.y][ray->map.x] == 'C')
			ray->hit = var->map.map[ray->map.y][ray->map.x];
	}
	if (ray->side == 0)
		ray->wall_dist = (ray->dist_side.x - ray->deltadist.x);
	if (ray->side == 1)
		ray->wall_dist = (ray->dist_side.y - ray->deltadist.y);
}

static void	get_height_and_draw(t_ray *ray, t_var *var, int x)
{
	int	line_height;
	int	start;
	int	end;

	line_height = H;
	if (ray->wall_dist != 0)
		line_height = (H / ray->wall_dist);
	start = H / 2 - line_height / 2;
	if (start < 0)
		start = 0;
	end = H / 2 + line_height / 2;
	if (end >= H)
		end = H;
	ray->start = start;
	ray->end = end;
	ray->line_height = line_height;
	get_ver_line(ray, var, x);
}

void	do_raycast(t_var *var, int gun)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < W)
	{
		ray.hit = 0;
		ray.side = 0;
		init_ray(&ray, var, x);
		calculate_dist(&ray, var);
		get_height_and_draw(&ray, var, x);
		x++;
	}
	ft_draw_minimap(var);
	ft_draw_weapon(var, gun);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}
