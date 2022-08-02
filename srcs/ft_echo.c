/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:33:56 by ssubielo          #+#    #+#             */
/*   Updated: 2022/08/03 00:33:58 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *ft_get_builtin(char *cmd)
{
	int i;
	int j;
	int e;
	char *builtin;
	
	i = 0;
	j = 0;
	e = 0;
	while(cmd[i] == ' ')
		i++;
	while(cmd[i + j] != ' ' && cmd[i])
		j++;
	if (j != 0)
		builtin = ft_calloc(sizeof(char),j);
	j -= 1;
	i +=j;
	while(j >= 0)
	{
		builtin[e] = cmd[i - j];
		e++;
		j--;
	}
	return (builtin);
}

void ft_check_echo(char *cmd)
{
	int i;
	
	i = 0;
	if (ft_strncmp(ft_get_builtin(cmd),"echo", 4))
	{
		while(cmd[i] == ' ')
			i++;
		i += 4;
		while(cmd[i] == ' ')
			i++;
		while(cmd[i] != ' ' && cmd[i])
		{
			ft_putchar_rl(cmd[i]);
			i++;
		}
	}
}
