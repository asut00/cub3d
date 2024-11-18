/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:06:25 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/27 20:27:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	dimension_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("dimension error\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	border_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("border error\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	char_error(char unexpected, t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("there is an unexpected \'", 2);
	ft_putchar_fd(unexpected, 2);
	ft_putstr_fd("\' in the map\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	map_config_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	if (var->player < 1)
		ft_putstr_fd("You need to have a player on the map to start playing\n",
			2);
	if (var->player > 1)
		ft_putstr_fd("Only one player can be on the map\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	hole_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("there is a hole in the map\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}
