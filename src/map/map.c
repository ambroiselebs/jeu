/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 23:54:39 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-07 23:54:39 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"

/*
	Redraw player on the map and updating his old pos
*/
void	update_player_pos(int old_x, int old_y, int new_x, int new_y, t_game *game, t_player *player)
{
	if (player->last_sprite == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->ground_sprite,
			old_x * game->tile_size,
			old_y * game->tile_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
			player->skin,
			new_x * game->tile_size,
			new_y * game->tile_size);
}

/*
	Decide which texture have to placed depending on the char code
*/
void	put_correct_texture(char c, int x, int y, t_game *game, t_player *player)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->ground_sprite,
				x * game->tile_size,
				y * game->tile_size);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
				player->skin,
				player->pos_x * game->tile_size,
				player->pos_y * game->tile_size);
}

/*
	Function to parse the map and put the correct texture using the `put_correct_texture` function
*/
void	draw_map(t_game *game, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			put_correct_texture(game->map[y][x], x, y, game, player);
			x++;
		}
		y++;
	}
}
