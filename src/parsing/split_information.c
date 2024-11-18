/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:40 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:47:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*skip_spaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (str + i);
}

static void	cmp_info(int i, t_var *var)
{
	if (!ft_strncmp(var->splitted_info[i], "WE ", 3))
	{
		if (var->textures[WE].exist++ == 1)
			double_error(var);
		var->textures[WE].data = skip_spaces(var->splitted_info[i], 3);
	}
	else if (!ft_strncmp(var->splitted_info[i], "EA ", 3))
	{
		if (var->textures[EA].exist++ == 1)
			double_error(var);
		var->textures[EA].data = skip_spaces(var->splitted_info[i], 3);
	}
	else if (!ft_strncmp(var->splitted_info[i], "F ", 2))
	{
		if (var->colors[F].exist++ == 1)
			double_error(var);
		var->colors[F].data = skip_spaces(var->splitted_info[i], 2);
	}
	else if (!ft_strncmp(var->splitted_info[i], "C ", 2))
	{
		if (var->colors[C].exist++ == 1)
			double_error(var);
		var->colors[C].data = skip_spaces(var->splitted_info[i], 2);
	}
}

static void	split_info(t_var *var)
{
	int		i;

	i = 0;
	while (i < ARG_NBR - 1)
	{
		if (!ft_strncmp(var->splitted_info[i], "NO ", 3))
		{
			if (var->textures[NO].exist++ == 1)
				double_error(var);
			var->textures[NO].data = skip_spaces(var->splitted_info[i], 3);
		}
		else if (!ft_strncmp(var->splitted_info[i], "SO ", 3))
		{
			if (var->textures[SO].exist++ == 1)
				double_error(var);
			var->textures[SO].data = skip_spaces(var->splitted_info[i], 3);
		}
		else
			cmp_info(i, var);
		i++;
	}
}

void	color_and_texture_exist_check(t_var *var)
{
	if (var->colors[C].exist != 1
		|| var->colors[F].exist != 1)
		rgb_error(var);
	if (var->textures[NO].exist != 1
		|| var->textures[EA].exist != 1
		|| var->textures[SO].exist != 1
		|| var->textures[WE].exist != 1)
		texture_error(var);
}

void	split_information(t_var *var)
{
	var->textures[NO].exist = 0;
	var->textures[SO].exist = 0;
	var->textures[WE].exist = 0;
	var->textures[EA].exist = 0;
	var->textures[F].exist = 0;
	var->textures[C].exist = 0;
	var->splitted_info = ft_split(var->file, '\n', var);
	while (*var->file == '\n')
		var->file++;
	var->map.map = ft_split_map(var->file, '\n', var);
	split_info(var);
	color_and_texture_exist_check(var);
	check_rgb(var);
}
