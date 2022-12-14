/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:22:57 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/05 18:23:00 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_meta(char	c)
{
	char	*base;
	int		x;

	base = "<<<>>>*?[]{}()|;&^$";
	x = 0;
	while (base[x])
	{
		if(c == base[x])
			return (1);
		x++;
	}
	return (0);
}
