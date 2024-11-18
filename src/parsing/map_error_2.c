/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:06:25 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/27 20:27:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	not_enough_arg_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Not enough arguments were given in the cub file\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	double_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("There's a double in the information given\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	rgb_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Something is wrong with the RGB colors\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	texture_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Something is wrong with the textures\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}
