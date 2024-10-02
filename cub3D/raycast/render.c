/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:16:35 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/26 13:35:18 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_draw3d(t_mlx *mlx, double angle, int x, int i)
{
	double	wall_height;
	int		start;
	int		end;
	int		data[2];
	float	distance;

	distance = mlx->ray[i].distance * cos(angle - mlx->cub->s.rotation_angle);
	wall_height = (HEIGHT * 32) / distance;
	start = (HEIGHT / 2) - (wall_height / 2);
	end = (HEIGHT / 2) + (wall_height / 2);
	data[0] = start;
	data[1] = wall_height;
	while (start < end && start < HEIGHT)
	{
		if (start >= 0 && start <= HEIGHT)
			mlx_put_pixel(mlx->img, x, start, get_texture_color(mlx, i, start,
					data));
		start++;
	}
}

void	lhyota(t_mlx *mlx)
{
	double	theta;
	double	increment;
	int		i;
	int		j;

	theta = mlx->cub->s.rotation_angle - (FOV_ANGLE / 2);
	increment = (FOV_ANGLE) / NUM_RAYS;
	i = 0;
	j = NUM_RAYS;
	while (i < NUM_RAYS)
	{
		mlx->ray[i].angle = normalize_angle(theta);
		ft_draw3d(mlx, theta, j, i);
		theta += increment;
		i++;
		j--;
	}
}

void	ft_put_in(int x, int y, mlx_image_t *img, int color)
{
	int	i;
	int	j;
	int	size;

	size = 8;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_floor_and_ceiling(t_mlx *mlx)
{
	int	floor_color;
	int	ceiling_color;
	int	i;
	int	j;

	floor_color = mlx->cub->f[0] << 24 
		| mlx->cub->f[1] << 16 | mlx->cub->f[2] << 8 | 255;
	ceiling_color = mlx->cub->c[0] << 24 
		| mlx->cub->c[1] << 16 | mlx->cub->c[2] << 8 | 255;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(mlx->img, j, i, ceiling_color);
			else
				mlx_put_pixel(mlx->img, j, i, floor_color);
			j++;
		}
		i++;
	}
}

void	ft_render(t_mlx *mlx)
{
	mlx_delete_image(mlx->win, mlx->img);
	mlx->img = mlx_new_image(mlx->win, WIDTH, HEIGHT);
	draw_floor_and_ceiling(mlx);
	ft_distance(mlx);
	lhyota(mlx);
	mini_map(mlx);
	draw_sprite(mlx, chose_sp_tex(mlx));
	draw_game_border(mlx);
	mlx_image_to_window(mlx->win, mlx->img, 0, 0);
}
