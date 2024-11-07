/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-07 00:03:24 by aberenge          #+#    #+#             */
/*   Updated: 2024-11-07 00:03:24 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*win_title;
	int			win_width;
	int			win_height;
	int			tile_size;
}	t_game;

#endif
