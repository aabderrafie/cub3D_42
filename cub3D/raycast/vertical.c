/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasfar <tlasfar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:05:48 by tlasfar           #+#    #+#             */
/*   Updated: 2024/09/13 21:14:53 by tlasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static t_vars	set_ver_vars(t_mlx *mlx, double angle, t_direction d)
{
	t_vars	v;

	v.xintercept = floor(mlx->cub->s.x / TILE_SIZE) * TILE_SIZE;
	if (d.is_right)
		v.xintercept += TILE_SIZE;
	v.yintercept = mlx->cub->s.y + (mlx->cub->s.x - v.xintercept) * tan(angle);
	v.xinc = TILE_SIZE;
	if (d.is_left)
		v.xinc *= -1;
	v.yinc = TILE_SIZE * tan(angle);
	if (d.is_up && v.yinc > 0)
		v.yinc *= -1;
	if (d.is_down && v.yinc < 0)
		v.yinc *= -1;
	v.next_x = v.xintercept;
	v.next_y = v.yintercept;
	if (d.is_left)
		v.next_x--;
	return (v);
}

static void	has_wall_at2(t_mlx *mlx, double angle, int i, t_vars v)
{
	t_direction	d;

	d = set_direction(angle);
	mlx->ray[i].v_hitting_on = 'D';
	if (d.is_left)
	{
		v.next_x -= (TILE_SIZE / 2);
		v.next_y += (TILE_SIZE / 2) * tan(angle);
	}
	if (d.is_right)
	{
		v.next_x += (TILE_SIZE / 2);
		v.next_y -= (TILE_SIZE / 2) * tan(angle);
	}
	mlx->ray[i].x_vert = v.next_x;
	mlx->ray[i].y_vert = v.next_y;
	mlx->ray[i].hit = 'D';
}

static void	has_wall_at1(t_mlx *mlx, double angle, int i, t_vars v)
{
	t_direction	d;

	d = set_direction(angle);
	if (d.is_left)
		v.next_x++;
	mlx->ray[i].x_vert = v.next_x;
	mlx->ray[i].y_vert = v.next_y;
}

void	get_vertical(t_mlx *mlx, double angle, int i)
{
	t_vars		v;
	t_direction	d;

	d = set_direction(angle);
	v = set_ver_vars(mlx, angle, d);
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
	mlx->ray[i].x_vert = v.next_x;
	mlx->ray[i].y_vert = v.next_y;
}
