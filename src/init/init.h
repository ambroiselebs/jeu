/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 00:07:13 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-07 00:07:13 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../../main.h"

typedef struct s_handle_touch_params
{
	t_game		*game;
}	t_handle_touch_params;

typedef struct s_exit_game_params
{
	t_game			*game;
}	t_exit_game_params;

int		exit_game(t_exit_game_params *params);
int		handle_window_touch(int key, t_handle_touch_params *params);
void	init_window(t_game *game);

#endif
