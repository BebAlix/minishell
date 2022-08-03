/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_universel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:22:57 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/05 18:23:00 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_meta(char	*str)
{
	char	*base;
	int		len;
	int		i;
	int		x;

	base = "<<<>>>*?[]{}()|;&^\$";
	len = ft_strlen(base);
	i = 0;
	while(str[i])
	{
		x = 0;
		while(x < len)
		{
			if(str[i] == base[x])
				return(1)
			x++;	
		}
		i++;
	}
	return(0);
}
