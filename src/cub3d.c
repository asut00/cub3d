/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:36:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/28 13:58:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(t_var *var)
{
	int	i;

	i = 0;
	while (i < NBR_OF_TEXTURES + 1)
	{
		var->textures->exist = 0;
		i++;
	}
	var->garbage_collector = 0;
	var->mouse_move_last_x = -1;
	var->colors[C].exist = 0;
	var->colors[F].exist = 0;
	var->shooting = 0;
	var->zoom = SIZE_SQUARE;
}

int	main(int ac, char **av, char **envp)
{
	t_var	var;

	check_args(ac, av, envp);
	var.path = av[1];
	init_vars(&var);
	read_file(&var);
	split_information(&var);
	check_map_component(&var);
	game_init(&var);
}
