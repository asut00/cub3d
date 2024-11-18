/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:51:01 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 14:27:36 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	read_file_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("file : \'", 2);
	ft_putstr_fd(var->path, 2);
	ft_putstr_fd("\' can't be read\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

static int	get_file_size(t_var *var)
{
	int		size;
	char	buff[1];
	int		check_read;
	int		fd;

	buff[0] = '\0';
	size = 0;
	check_read = 1;
	fd = open(var->path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (check_read == 1)
	{
		check_read = read(fd, buff, 1);
		if (check_read == -1)
			read_file_error(var);
		if (check_read)
			size++;
	}
	close(fd);
	return (size);
}

static void	open_file_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("file : \'", 2);
	ft_putstr_fd(var->path, 2);
	ft_putstr_fd("\' doesn't exist or has been deleted\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	no_map_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("file is empty, doesn't exist, or access denied\n", 2);
	clear_garbage_and_exit(var, EXIT_FAILURE);
}

void	read_file(t_var *var)
{
	int		fd;
	int		size;
	int		check_read;
	char	*str;

	str = NULL;
	size = get_file_size(var);
	if (!size)
		no_map_error(var);
	str = ft_malloc((size + 1) * sizeof(char), var);
	fd = open(var->path, O_RDONLY);
	if (fd == -1)
		open_file_error(var);
	check_read = read(fd, str, size);
	if (check_read == -1)
		read_file_error(var);
	close(fd);
	str[size] = 0;
	var->file = str;
}
