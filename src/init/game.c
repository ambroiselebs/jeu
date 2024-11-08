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
	printf("\n\nExit game\n\n");
	mlx_destroy_window(params->game->mlx, params->game->mlx_win);
	free_map(params->game);
	exit(0);
	return (0);
}
/*
	Funtion to laod every required image by the window (wall, blank...)
*/
/* void	init_window_images(t_game *game)
{

} */

/*
	Initialize windows with corect informations
	win_width/height = Windows size
	tile_size = texture size
	win_title = Windows title
*/
void	init_window(t_game *game)
{
	game->tile_size = 32;
	game->win_width = 51;
	game->win_height = 29;
	game->win_title = "jeu";
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->win_width * game->tile_size,
			game->win_height * game->tile_size,
			game->win_title);
}
