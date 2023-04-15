/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:37:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/21 18:19:04 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char *argv[])
{
	if (argc == 2)
		game_init(argv[argc - 1]);
	else
		ft_printf("Error:\nMap is missing!\n");
	return (0);
}

// int main (int argc, char *argv[])
// {
// 	func(argc, argv);
// 	system("leaks so_long.out");
// }