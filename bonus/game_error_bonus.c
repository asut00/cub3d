/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:30:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/22 12:30:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	mlx_creation_error(t_var *var)
{
	ft_putstr_fd("Error\ncritical failure during mlx init\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	window_creation_error(t_var *var)
{
	int	j;

	j = 0;
	while (j < NBR_OF_TEXTURES_BONUS)
		mlx_destroy_image(var->mlx, var->textures[j++].img);
	free(var->mlx);
	ft_putstr_fd("Error\ncritical failure during window creation\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	img_creation_error(t_var *var)
{
	int	j;

	ft_putstr_fd("Error\ncritical failure during image creation\n", 2);
	mlx_destroy_window(var->mlx, var->win);
	// mlx_destroy_display(var->mlx);
	j = 0;
	while (j < NBR_OF_TEXTURES_BONUS)
		mlx_destroy_image(var->mlx, var->textures[j++].img);
	free(var->mlx);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	data_addr_creation_error(t_var *var)
{
	int	j;

	ft_putstr_fd("Error\ncritical failure during image addresse creation\n", 2);
	mlx_destroy_window(var->mlx, var->win);
	// mlx_destroy_display(var->mlx);
	j = 0;
	while (j < NBR_OF_TEXTURES_BONUS)
		mlx_destroy_image(var->mlx, var->textures[j++].img);
	free(var->mlx);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

int	rage_quited(t_var *var)
{
	int	j;

	j = 0;
	while (j < NBR_OF_TEXTURES_BONUS)
		mlx_destroy_image(var->mlx, var->textures[j++].img);
	mlx_destroy_image(var->mlx, var->img);
	mlx_destroy_window(var->mlx, var->win);
	// mlx_destroy_display(var->mlx);
	free(var->mlx);
	clear_garbage_and_exit(var, EXIT_SUCCESS);
	return (0);
}
