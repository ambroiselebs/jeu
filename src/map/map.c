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
	Decide which texture have to placed depending on the char code
*/
void	put_correct_texture(char c, t_game *game, t_player *player)
{
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
			put_correct_texture(game->map[y][x], game, player);
			x++;
		}
		y++;
	}
}
