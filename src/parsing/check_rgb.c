/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:40 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:47:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	atoi_spe_rgb(t_var *var, t_def type, t_rgb rgb, char **str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < NBR_INT_MAX_RGB && ft_isdigit(**str))
	{
		n = n * 10 + (**str - '0');
		*str = *str + 1;
		i++;
	}
	if (i == 0 || n > RGB_MAX)
		rgb_error(var);
	var->colors[type].rgb[rgb] = n;
}

static int	sixteenth_power(int squared)
{
	int	ret;

	ret = 1;
	while (squared--)
		ret *= 16 * 16;
	return (ret);
}

static void	stock_rgb(t_var *var)
{
	int	type;
	int	rgb;

	type = 0;
	while (type < RGB_INFO_NBR)
	{
		var->colors[type].value = 0;
		rgb = 0;
		while (rgb < RGB_NBR)
		{
			var->colors[type].value += var->colors[type].rgb[rgb]
				* sixteenth_power(2 - rgb);
			rgb++;
		}
		type++;
	}
}

void	check_rgb(t_var *var)
{
	int		type;
	int		rgb;
	char	*str;

	type = 0;
	while (type < RGB_INFO_NBR)
	{
		rgb = 0;
		str = var->colors[type].data;
		while (rgb < RGB_NBR)
		{
			atoi_spe_rgb(var, type, rgb, &str);
			rgb++;
			if ((rgb < RGB_NBR && *str != ',')
				|| (rgb == RGB_NBR && *str != '\0'))
				rgb_error(var);
			str++;
		}
		type++;
	}
	stock_rgb(var);
}
