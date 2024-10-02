/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:05:46 by tlasfar           #+#    #+#             */
/*   Updated: 2024/09/26 13:50:36 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static t_vars	set_hor_vars(t_mlx *mlx, double angle, t_direction d)
{
	t_vars	v;

	v.yintercept = floor(mlx->cub->s.y / TILE_SIZE) * TILE_SIZE;
	if (d.is_down)
		v.yintercept += TILE_SIZE;
	v.xintercept = mlx->cub->s.x + (mlx->cub->s.y - v.yintercept) / tan(angle);
	v.yinc = TILE_SIZE;
	if (d.is_up)
		v.yinc *= -1;
	v.xinc = TILE_SIZE / tan(angle);
	if (d.is_right && v.xinc < 0)
		v.xinc *= -1;
	if (d.is_left && v.xinc > 0)
		v.xinc *= -1;
	v.next_x = v.xintercept;
	v.next_y = v.yintercept;
	if (d.is_up)
		v.next_y--;
	return (v);
}

static void	has_wall_at2(t_mlx *mlx, double angle, int i, t_vars v)
{
	t_direction	d;

	d = set_direction(angle);
	mlx->ray[i].h_hitting_on = 'D';
	if (d.is_up)
		v.next_y += 1;
	if (d.is_up)
	{
		v.next_y -= (TILE_SIZE / 2);
		v.next_x += (TILE_SIZE / 2) / tan(angle);
	}
	if (d.is_down)
	{
		v.next_y += (TILE_SIZE / 2);
		v.next_x -= (TILE_SIZE / 2) / tan(angle);
	}
	mlx->ray[i].x_horz = v.next_x;
	mlx->ray[i].y_horz = v.next_y;
}

static void	has_wall_at1(t_mlx *mlx, double angle, int i, t_vars v)
{
	t_direction	d;

	d = set_direction(angle);
	if (d.is_up)
		v.next_y++;
	mlx->ray[i].x_horz = v.next_x;
	mlx->ray[i].y_horz = v.next_y;
}

void	get_horizontal(t_mlx *mlx, double angle, int i)
{
	t_vars		v;
	t_direction	d;

	d = set_direction(angle);
	v = set_hor_vars(mlx, angle, d);
	while (v.next_x > 0 && v.next_y > 0 && v.next_x < mlx->map_width
		&& v.next_y < mlx->map_height)
	{
		if (has_wall_at(mlx, v.next_x, v.next_y) == 2)
			return (has_wall_at2(mlx, angle, i, v));
		if (has_wall_at(mlx, v.next_x, v.next_y) == 1)
			return (has_wall_at1(mlx, angle, i, v));
		v.next_x += v.xinc;
		v.next_y += v.yinc;
	}
	mlx->ray[i].x_horz = v.next_x;
	mlx->ray[i].y_horz = v.next_y;
}
