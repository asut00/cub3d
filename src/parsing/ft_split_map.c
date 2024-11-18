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

#include "cub3d.h"

static int	ft_strreallen(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	count_words_map(char *s, char c, t_var *var)
{
	int		i;
	int		count;
	int		max_length;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			if (s[++i] == c)
				dimension_error(var);
		if (s[i])
			count++;
		max_length = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			max_length++;
		}
		if (max_length > var->map.max_col)
			var->map.max_col = max_length;
	}
	return (count);
}

static char	*create_line(char *src, int n, t_var *var)
{
	char	*str;

	str = ft_calloc(var->map.max_col + 1, sizeof(char), var);
	ft_strlcat(str, src, n + 1);
	while (n++ < var->map.max_col + 1)
		ft_strlcat(str, " ", n);
	return (str);
}

char	**ft_split_map(char *s, char c, t_var *var)
{
	int		i;
	int		j;
	// int		tmp_max_len;
	char	**splitted;

	i = 0;
	j = 0;
	var->map.max_col = 0;
	var->map.max_row = count_words_map(s, c, var);
	splitted = (char **)ft_calloc(var->map.max_row + 1, sizeof(char *), var);
	while (i < var->map.max_row)
	{
		while (s[j] && s[j] == c)
			j++;
		splitted[i] = create_line(&s[j], ft_strreallen(&s[j], c), var);
		// tmp_max_len = ft_strreallen(&s[j], c);
		j += ft_strreallen(&s[j], c);
		i++;
	}
	return (splitted);
}
