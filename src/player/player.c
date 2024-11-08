/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 12:42:56 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-07 12:42:56 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "mlx.h"
# include "../map/map.h"

/*
	Load every image used by the player
*/
void	init_player_image(t_player *player, t_game *game)
{
	player->skin = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &game->tile_size, &game->tile_size);
	//player->skin = mlx_png_file_to_image(game->mlx, "assets/player.png", &game->tile_size, &game->tile_size);
}

/*
	Locate the player on map when starting the game
*/
void	get_player_pos_on_map(t_player *player, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (game->map[y][x] == 'P')
			{
				player->pos_x = x;
				player->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

/*
	Init the player with basic value
*/
void	init_player(t_player *player, t_game *game)
{
	player->last_sprite = '0';
	player->money = 10;
	init_player_image(player, game);
	get_player_pos_on_map(player, game);
}

/*
	Function to move the player and update the map
*/
void	move_player(int new_pos_x, int new_pos_y, t_game *game, t_player *player)
{
	game->map[player->pos_y][player->pos_x] = '0';
	printf("%c\n", game->map[player->pos_y][player->pos_x]);
	player->pos_x = new_pos_x;
	player->pos_y = new_pos_y;
	player->last_sprite = game->map[player->pos_y][player->pos_x];
	game->map[player->pos_y][player->pos_x] = 'P';
	draw_map(game, player);
}

/*
	Listening for key entries
	13 = w
	1 = s
	0 = a
	2 = d
*/
int	handle_player_movement(int key, t_handle_player_movement_params *params)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = params->player->pos_x;
	new_pos_y = params->player->pos_y;
	if (key == 13)
	{
		new_pos_y--;
		if (params->game->map[new_pos_y][new_pos_x] != '1')
			move_player(new_pos_x, new_pos_y, params->game, params->player);
	}
	if (key == 1)
	{
		new_pos_y++;
		if (params->game->map[new_pos_y][new_pos_x] != '1')
			move_player(new_pos_x, new_pos_y, params->game, params->player);
	}
	if (key == 0)
	{
		new_pos_x--;
		if (params->game->map[new_pos_y][new_pos_x] != '1')
			move_player(new_pos_x, new_pos_y, params->game, params->player);
	}
	if (key == 2)
	{
		new_pos_x++;
		if (params->game->map[new_pos_y][new_pos_x] != '1')
			move_player(new_pos_x, new_pos_y, params->game, params->player);
	}
	return(0);
}
