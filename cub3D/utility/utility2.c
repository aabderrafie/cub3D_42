/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:52:17 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/26 15:19:47 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	key_escape(int key_code, t_mlx *mlx)
{
	if (key_code == MLX_KEY_ESC)
	{
		mlx_close_window(mlx->win);
		mlx_terminate(mlx->win);
		exit(0);
	}
}

void	key_left(mlx_key_data_t key_data, t_mlx *mlx)
{
	if (key_data.key == MLX_KEY_LEFT && key_data.action)
		mlx->cub->s.rotation_angle += 0.1;
}

void	key_right(mlx_key_data_t key_data, t_mlx *mlx)
{
	if (key_data.key == MLX_KEY_RIGHT && key_data.action)
		mlx->cub->s.rotation_angle -= 0.1;
}

void	draw_game_border(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (x < 10 || x > WIDTH - 11 || y < 10 || y > HEIGHT - 10)
				mlx_put_pixel(mlx->img, x, y, 0x111111FF);
			y++;
		}
		x++;
	}
}
