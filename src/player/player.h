/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 01:37:30 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-08 01:37:30 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../../main.h"

typedef struct s_game t_game; // Forward declaration of 't_game'

typedef struct s_handle_player_movement_params
{
	t_game		*game;
	struct s_player	*player;
}	t_handle_player_movement_params;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	last_sprite;
	void	*skin;
	int		money;
}	t_player;

void	get_player_pos_on_map(t_player *player, t_game *game);
void	init_player(t_player *player, t_game *game);
void	move_player(int new_pos_x, int new_pos_y, t_game *game, t_player *player);
int		handle_player_movement(int key, t_handle_player_movement_params *params);

#endif
