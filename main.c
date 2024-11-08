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
#include "src/map/map.h"
#include "src/player/player.h"
#include "mlx.h"

int	main(void)
{
	t_game								game;
	t_player							player;
	t_exit_game_params					exit_game_params;
	t_handle_player_movement_params		handle_player_mouvement_params;

	/* Init window */
	init_window(&game);

	/* Init map */
	init_map(&game);

	/* Init player */
	init_player(&player, &game);
	handle_player_mouvement_params.game = &game;
	handle_player_mouvement_params.player = &player;
	mlx_key_hook(game.mlx_win, handle_player_movement, &handle_player_mouvement_params);

	draw_map(&game, &player);

	/* Handle windows exit procedure (using button) */
	exit_game_params.game = &game;
	mlx_hook(game.mlx_win, 17, 1L << 17, exit_game, &exit_game_params);

	/* Main Loop */
	mlx_loop(game.mlx);
	return (0);
}
