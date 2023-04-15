/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:37:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 18:36:35 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	main(int argc, char *argv[])
{
	if (argc == 2)
		return (game_init(argv[argc - 1]));
	else
		ft_printf("ERROR:\nMap is missing");
	return (EXIT_SUCCESS);
}

// int main (int argc, char *argv[])
// {
// 	if (func(argc, argv))
// 		return (EXIT_FAILURE);
// 	system("leaks bonus.out");
// 	return (EXIT_SUCCESS);
// }