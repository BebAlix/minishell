/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:17:24 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/09 00:06:45 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	nbline(t_def_char *s, char c)
{
	int	i;
	int	nbl;

	i = 0;
	nbl = 1;
	while (s[i].c)
	{
		if (s[i].c == c && s[i].c && s[i].quotes == 0)
			nbl++;
		i++
	}
	return (nbl);
}

static int	nbcolumn(t_def_char *s, char c, int len)
{
	int	i;
	int	nbc;
	int	x;

	x = 0;
	i = 0;
	nbc = 0;
	while (s[i].c == c)
		i++;
	while (x < len)
	{
		while (s[i].c != c && s[i].c)
			i++;
		while (s[i].c == c)
			i++;
		x++;
	}
	while (s[i].c != c && s[i].c)
	{
		i++;
		nbc++;
	}
	return (nbc);
}

static int	ft_start(char const *s, char c, int len)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (x < len && s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		x++;
	}
	return (i);
}

t_def_char	**ft_split(t_def_char *s, char c)
{
	int		i;
	int		len;
	t_def_char	**str;

	len = nbline(s, c);
	i = -1;
	if (s[0] == 0)
	{
		str = ft_calloc(sizeof(t_def_char *), 1);
		if (!str)
			return (NULL);
		return (str);
	}
	str = ft_calloc(sizeof(t_def_char *), len + 1);
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = ft_substr(s, ft_start(s, c, i), nbcolumn(s, c, i));
	return (str);
}
