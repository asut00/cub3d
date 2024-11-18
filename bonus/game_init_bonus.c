/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:30:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/22 12:30:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	error_mlx(char *msg, int text_created, t_var *var)
{
	int	j;

	j = 0;
	while (j < text_created)
		mlx_destroy_image(var->mlx, var->textures[j++].img);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	ft_putstr_fd(msg, 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

static void	init_path(t_var *var)
{
	var->textures[DOOR].data = DOOR_FILE;
	var->textures[GUN_0].data = GUN_0_FILE;
	var->textures[GUN_1].data = GUN_1_FILE;
	var->textures[GUN_2].data = GUN_2_FILE;
	var->textures[GUN_3].data = GUN_3_FILE;
	var->textures[GUN_4].data = GUN_4_FILE;
}

static int	playing_the_game(t_var *var)
{
	if (var->shooting >= GUN_0)
	{
		do_raycast(var, var->shooting);
		usleep(40000);
		var->shooting++;
		if (var->shooting > GUN_4)
			var->shooting = 0;
	}
	else
		do_raycast(var, GUN_0);
	return (1);
}

static void	get_data_from_xpm(t_var *var)
{
	int		i;

	i = 0;
	init_path(var);
	while (i < NBR_OF_TEXTURES_BONUS)
	{
		var->textures[i].img = mlx_xpm_file_to_image(var->mlx,
				var->textures[i].data, &var->textures[i].length,
				&var->textures[i].height);
		if (!var->textures[i].img)
			error_mlx("error during the conversion of xpm files\n", i, var);
		var->textures[i].addr = mlx_get_data_addr(var->textures[i].img,
				&var->textures[i].bpp, &var->textures[i].line_l,
				&var->textures[i].endian);
		if (!var->textures[i].addr)
			error_mlx("error creation of data addr\n", i, var);
		i++;
	}
}

void	game_init(t_var *var)
{
	var->zoom = SIZE_SQUARE;
	var->mlx = mlx_init();
	if (!var->mlx)
		mlx_creation_error(var);
	get_data_from_xpm(var);
	var->win = mlx_new_window(var->mlx, W, H, "cub3d");
	if (!var->win)
		window_creation_error(var);
	var->img = mlx_new_image(var->mlx, W, H);
	if (!var->img)
		img_creation_error(var);
	var->data_addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
			&var->line_length, &var->endian);
	if (!var->data_addr)
		data_addr_creation_error(var);
	do_raycast(var, GUN_0);
	mlx_hook(var->win, 2, 1, handle_keyboard, var);
	mlx_hook(var->win, 6, 1L << 6, handle_mouse, var);
	mlx_hook(var->win, 17, 1L << 3, rage_quited, var);
	mlx_loop_hook(var->mlx, &playing_the_game, var);
	mlx_loop(var->mlx);
}
