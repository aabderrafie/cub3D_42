/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:39:19 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:54:16 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	key_w(mlx_key_data_t key_data, t_mlx *mlx)
{
	if (key_data.key == MLX_KEY_W && key_data.action)
	{
		if (mlx->cub->map[(int)(mlx->cub->s.y) / TILE_SIZE][(int)mlx->cub->s.x
			/ TILE_SIZE] != '1')
		{
			mlx->cub->s.y -= sin(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.y += sin(mlx->cub->s.rotation_angle) * 10;
			mlx->cub->s.x += cos(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.x -= cos(mlx->cub->s.rotation_angle) * 10;
		}
	}
}

void	key_s(mlx_key_data_t key_data, t_mlx *mlx)
{
	if (key_data.key == MLX_KEY_S && key_data.action)
	{
		if (mlx->cub->map[(int)(mlx->cub->s.y) / TILE_SIZE][(int)mlx->cub->s.x
			/ TILE_SIZE] != '1')
		{
			mlx->cub->s.y += sin(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.y -= sin(mlx->cub->s.rotation_angle) * 10;
			mlx->cub->s.x -= cos(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.x += cos(mlx->cub->s.rotation_angle) * 10;
		}
	}
}

void	key_a(mlx_key_data_t key_data, t_mlx *mlx)
{
	if (key_data.key == MLX_KEY_A && key_data.action)
	{
		if (mlx->cub->map[(int)(mlx->cub->s.y) / TILE_SIZE][(int)mlx->cub->s.x
			/ TILE_SIZE] != '1')
		{
			mlx->cub->s.x -= sin(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.x += sin(mlx->cub->s.rotation_angle) * 10;
			mlx->cub->s.y -= cos(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.y += cos(mlx->cub->s.rotation_angle) * 10;
		}
	}
}

void	key_d(mlx_key_data_t key_data, t_mlx *mlx)
{
	if (key_data.key == MLX_KEY_D && key_data.action)
	{
		if (mlx->cub->map[(int)(mlx->cub->s.y) / TILE_SIZE][(int)mlx->cub->s.x
			/ TILE_SIZE] != '1')
		{
			mlx->cub->s.x += sin(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.x -= sin(mlx->cub->s.rotation_angle) * 10;
			mlx->cub->s.y += cos(mlx->cub->s.rotation_angle) * 10;
			if (check_tile(mlx))
				mlx->cub->s.y -= cos(mlx->cub->s.rotation_angle) * 10;
		}
	}
}

void	key_press(mlx_key_data_t key_data, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	key_escape(key_data.key, mlx);
	key_left(key_data, mlx);
	key_right(key_data, mlx);
	key_w(key_data, mlx);
	key_s(key_data, mlx);
	key_a(key_data, mlx);
	key_d(key_data, mlx);
}
