/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:41:32 by ssubielo          #+#    #+#             */
/*   Updated: 2022/08/04 03:57:07 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_check_quotes(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			i++;
			while (input[i] != '\'')
			{
				if (input[i] == '\0')
					return (write(2, "ERROR : WRONG QUOTES\n", 21));
				i++;
			}
		}
		else if (input[i] == '"')
		{
			i++;
			while (input[i] != '"')
			{
				if (input[i] == '\0')
					return (write(2, "ERROR : WRONG QUOTES\n", 21));
				i++;
			}
		}
		i++;
	}
	return (0);
}

static int	ft_update_stat(char c)
{
	static int	stat;

	if (c == ' ' && stat == 0)
		stat = 3;
	else if (c != ' ' && stat == 3)
		stat = 0;
	if (c == '\'' && stat == 0)
		stat = 1;
	else if (c == '\'' && stat == 1)
		stat = 0;
	else if (c == '"' && stat == 0)
		stat = 2;
	else if (c == '"' && stat == 2)
		stat = 0;
	return (stat);
}

static void	ft_no_quotes(t_def_char *line, char *input, int stat)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] == ' ')
		i++;
	while (input[i])
	{
		stat = ft_update_stat(input[i]);
		if ((input[i] != ' ' || stat != 0) && (input[i] != '\'' || \
			stat == 2) && (input[i] != '"' || stat == 1))
		{
			line[j].c = input[i];
			line[j].quotes = stat;
			line[j].bool_m = ft_check_meta(line[j].c);
			j++;
		}
		i++;
		while (input[i] == ' ' && stat == 3)
			i++;
	}
	if (input[i - 1] == ' ' && stat == 3)
		line[j - 1].c = '\0';
}

static t_def_char	*ft_modif_line(char *input)
{
	t_def_char	*line;
	int			stat;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (input[i] == ' ')
		i++;
	while (input[i])
	{
		stat = ft_update_stat(input[i]);
		if ((input[i] != ' ' || stat != 0) && (input[i] != '\'' || \
			stat == 2) && (input[i] != '"' || stat == 1))
			j++;
		i++;
		while (input[i] == ' ' && stat == 3)
			i++;
	}
	if (input[i - 1] == ' ' && stat == 3)
		j--;
	line = ft_calloc(sizeof(t_def_char), j + 1);
	if (!line)
		return (NULL);
	ft_no_quotes(line, input, stat);
	return (line);
}

t_def_char	*ft_parce_input(char *input)
{
	t_def_char	*line;

	if (ft_check_quotes(input))
		return (NULL);
	line = ft_modif_line(input);
	return (line);
}
