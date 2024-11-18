/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:30:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:46:58 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static int	ft_strreallen(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	count_words(char *s, char c, t_var *var)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (!count)
		no_map_error(var);
	if (count < ARG_NBR)
		not_enough_arg_error(var);
}

char	**ft_split(char *s, char c, t_var *var)
{
	int		i;
	int		j;
	int		count;
	char	**splitted;

	i = 0;
	j = 0;
	count_words(s, c, var);
	count = ARG_NBR - 1;
	splitted = (char **)ft_calloc(count + 1, sizeof(char *), var);
	while (i < count)
	{
		while (s[j] && (s[j] == c || s[j] == ' '))
			j++;
		splitted[i] = ft_substr(s, j, ft_strreallen(&s[j], c), var);
		j += ft_strreallen(&s[j], c);
		i++;
	}
	var->file += j;
	return (splitted);
}
