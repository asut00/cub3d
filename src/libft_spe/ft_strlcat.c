/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:23:47 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 13:06:07 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	ft_strlcat(char *dest, const char *src, int n)
{
	int	len_dest;
	int	len_src;
	int	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= n)
		return (n + len_src);
	i = 0;
	while (src[i] && i < n - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (i == n - len_dest - 1)
		dest[len_dest + i] = 0;
	else
		dest[len_dest + len_src] = 0;
	return (len_dest + len_src);
}
