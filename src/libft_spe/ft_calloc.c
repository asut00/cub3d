/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:15:52 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/22 10:21:41 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	*ft_calloc(int nb_elem, int size_elem, t_var *var)
{
	void	*tab;
	int		i;

	i = 0;
	tab = (void *)ft_malloc(nb_elem * size_elem, var);
	while (i < nb_elem * size_elem)
	{
		*(unsigned char *)(tab + i) = 0;
		i++;
	}
	return (tab);
}
