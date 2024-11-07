/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 00:03:13 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-07 00:03:13 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "src/init/init.h"
#include "mlx.h"

int	main(void)
{
	t_game					game;
	t_handle_touch_params	init_window_touch_params;
	t_exit_game_params		exit_game_params;

	init_window(&game);
	init_window_touch_params.game = &game;
	mlx_key_hook(game.mlx_win, handle_window_touch, &init_window_touch_params);
	exit_game_params.game = &game;
	mlx_hook(game.mlx_win, 17, 1L << 17, exit_game, &exit_game_params);
	mlx_loop(game.mlx);
	return (0);
}
