/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:23:12 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/11 18:35:29 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static void	ft_garbageadd_front(t_garbage **garbage, t_garbage *new)
{
	new->next = *garbage;
	*garbage = new;
}

static t_garbage	*ft_garbagenew(void *content)
{
	t_garbage	*new_elem;

	new_elem = (t_garbage *)malloc(sizeof(t_garbage));
	if (!new_elem)
		return (free(content), NULL);
	new_elem->content = content;
	new_elem->next = 0;
	return (new_elem);
}

void	*ft_malloc(int size, t_var *pvar)
{
	void		*ptr;
	t_garbage	*garbage;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("memory allocation has fail\n", 2);
		clear_garbage_and_exit(pvar, EXIT_FAILURE);
	}
	garbage = ft_garbagenew(ptr);
	if (!(garbage))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("memory allocation has fail\n", 2);
		clear_garbage_and_exit(pvar, EXIT_FAILURE);
	}
	ft_garbageadd_front(&pvar->garbage_collector, garbage);
	return (ptr);
}

void	ft_free(void *content_to_find, t_var *var)
{
	t_garbage	*current_elem;
	t_garbage	*previous_elem;

	if (content_to_find == 0)
		return ;
	current_elem = var->garbage_collector;
	if (current_elem->content == content_to_find)
	{
		var->garbage_collector = current_elem->next;
		return (free(current_elem->content), free(current_elem));
	}
	previous_elem = current_elem;
	current_elem = current_elem->next;
	while (current_elem)
	{
		if (current_elem->content == content_to_find)
		{
			previous_elem->next = current_elem->next;
			return (free(current_elem->content), free(current_elem));
		}
		previous_elem = current_elem;
		current_elem = current_elem->next;
	}
}

void	clear_garbage_and_exit(t_var *var, int exit_value)
{
	t_garbage	*current_node;
	t_garbage	*next_node;

	current_node = var->garbage_collector;
	while (current_node)
	{
		next_node = current_node->next;
		if (current_node->content)
			free(current_node->content);
		free(current_node);
		current_node = next_node;
	}
	var->garbage_collector = 0;
	exit (exit_value);
}
