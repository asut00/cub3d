/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:03:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/28 14:04:43 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static void	check_ac(int ac)
{
	if (ac < 2)
	{
		ft_putstr_fd("Error\nNo file -> no game\n", 2);
		ft_putstr_fd("no game -> no game\n", 2);
		exit(1);
	}
	if (ac > 2)
	{
		ft_putstr_fd("Error\nThis is too much for the program\n", 2);
		exit(1);
	}
}

static void	check_av(char **av)
{
	if (ft_strlen(av[1]) < 4)
	{
		ft_putstr_fd("Error\nfile name is not the write format\n", 2);
		ft_putstr_fd("Format accepted : 'Xcub', X being a string\n", 2);
		exit(1);
	}
	if (ft_strcmp(&av[1][ft_strlen(av[1]) - 4], ".cub"))
	{
		ft_putstr_fd("Error\nfile name doesn't end with '.cub'\n", 2);
		exit(1);
	}
}

static void	check_envp(char **envp)
{
	if (!envp || !envp[1])
	{
		ft_putstr_fd("No environment variable found, the path won't work", 2);
		exit(1);
	}
}

void	check_args(int ac, char **av, char **envp)
{
	check_ac(ac);
	check_av(av);
	check_envp(envp);
}
