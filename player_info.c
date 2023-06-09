/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:52:02 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/08 16:35:20 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_dir(char player_dir, int arg)
{
	if (arg == 0 && (player_dir == 'N' || player_dir == 'S'))
		return (0);
	if (arg == 1 && (player_dir == 'E' || player_dir == 'W'))
		return (0);
	if (arg == 0 && player_dir == 'E')
		return (1);
	if (arg == 0 && player_dir == 'W')
		return (-1);
	if (arg == 1 && player_dir == 'S')
		return (1);
	if (arg == 1 && player_dir == 'N')
		return (-1);
	return (0);
}

int	get_face(t_pro *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			return (1);
		return (3);
	}
	else
	{
		if (ray->raydir_y > 0)
			return (2);
		return (0);
	}
}

int	player_pos(char dir, int pos_col, int pos_row, t_vars *vars)
{
	static char	one_dir;
	static int	col;
	static int	row;

	if (vars)
	{
		vars->pos_x = col + 0.5;
		vars->pos_y = row + 0.5;
		vars->dir = one_dir;
		return (0);
	}
	if (one_dir && pos_col == -1)
		return (0);
	if (!one_dir && dir && !vars)
		one_dir = dir;
	if (!col && pos_col && !vars)
		col = pos_col;
	if (!row && pos_row && !vars)
		row = pos_row;
	return (1);
}
