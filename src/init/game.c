/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 00:06:12 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-07 00:06:12 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "mlx.h"

/*
	Handling exit game event
	destroy window properly => exit the program
*/
int	exit_game(t_exit_game_params *params)
{
	printf("\n\n");
	mlx_destroy_window(params->game->mlx, params->game->mlx_win);
	exit(0);
	return (0);
}

/*
	Handling windows related keyboard entries
	ESCAPE (macos/windows/linux) => exit game
*/
int	handle_window_touch(int key, t_handle_touch_params *params)
{
	t_exit_game_params	exit_game_params;

	exit_game_params.game = params->game;
	if (key == 65307 || key == 53)
		exit_game(&exit_game_params);
	return (0);
}

/*
	Initialize windows with corect informations
	win_width/height = Windows size
	tile_size = texture size
	win_title = Windows title
*/
void	init_window(t_game *game)
{
	game->tile_size = 32;
	game->win_width = 500;
	game->win_height = 500;
	game->win_title = "jeu";
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->win_width, game->win_height, game->win_title);
}
