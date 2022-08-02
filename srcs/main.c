/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:54:03 by equesnel          #+#    #+#             */
/*   Updated: 2022/08/02 18:10:10 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_read()
{
	char	*input;

	input = NULL;
	while (1)
	{
		if (input)
		{
			free(input);
			input = NULL;
		}
		input = readline("$>");
		if (input)
			add_history(input);
		printf("%s\n", input);
	}
}

int	main(void)
{
	ft_read();
	return (0);
}
