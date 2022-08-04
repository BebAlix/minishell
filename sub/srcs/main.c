/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 03:28:22 by equesnel          #+#    #+#             */
/*   Updated: 2022/08/04 03:56:35 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int ac, char **av)
{
	t_def_char	*line;
	int			i;

	i = 0;
	line = 0;
	if (ac < 2)
		return (0);
	line = ft_parce_input(av[1]);
	if (!line)
		return (0);
	while (line[i].c)
		ft_putchar_fd(line[i++].c, 1);
	free(line);
}
