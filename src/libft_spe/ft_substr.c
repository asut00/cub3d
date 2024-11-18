/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:40:44 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 14:40:48 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

char	*ft_substr(char const *str, int start, int len, t_var *var)
{
	int		len_dest;
	char	*substr;

	if (start >= ft_strlen(str))
		len_dest = 0;
	else
		len_dest = ft_strlen(str + start);
	if (len_dest > len)
		len_dest = len;
	substr = ft_calloc(len_dest + 1, sizeof(char), var);
	if (len_dest == 0)
		ft_strlcpy(substr, str, len_dest + 1);
	else
		ft_strlcpy(substr, str + start, len_dest + 1);
	return (substr);
}
