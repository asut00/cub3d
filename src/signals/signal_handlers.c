/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:37:30 by asuteau           #+#    #+#             */
/*   Updated: 2024/09/10 13:37:31 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse(int x, int y, t_var *var)
{
	int	delta_x;

	(void)y;
	if (var->mouse_move_last_x == -1)
		var->mouse_move_last_x = x;
	delta_x = x - var->mouse_move_last_x;
	if (delta_x > 0)
		rotate(var, 0.03);
	else if (delta_x < 0)
		rotate(var, -0.03);
	var->mouse_move_last_x = x;
	do_raycast(var, GLOVES);
	return (0);
}

int	handle_keyboard(int keysym, t_var *var)
{
	// printf("keysym is : %d\n", keysym);
	if (keysym == KEY_ESC)
		rage_quited(var);
	else if (keysym == KEY_W)
		move_straight(var, FORWARD);
	else if (keysym == KEY_A)
		straf(var, LEFT);
	else if (keysym == KEY_S)
		move_straight(var, BACKWARD);
	else if (keysym == KEY_D)
		straf(var, RIGHT);
	else if (keysym == KEY_LEFT_ARR)
		rotate(var, -0.05);
	else if (keysym == KEY_RIGHT_ARR)
		rotate(var, 0.05);
	else if (keysym == KEY_PLUS)
		zoom_minimap(var);
	else if (keysym == KEY_MINUS)
		dezoom_minimap(var);
	else if (keysym == KEY_E)
		try_opening_doors(var);
	do_raycast(var, GLOVES);
	return (0);
}
