/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 01:37:22 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-08 01:37:22 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../player/player.h"  // This include remains, assuming player structures are needed
# include "../../main.h"
# include "../init/init.h"

void	free_map(t_game *game);
void	init_map(t_game *game);
void	put_correct_texture(char c, t_game *game, t_player *player);
void	draw_map(t_game *game, t_player *player);

#endif
