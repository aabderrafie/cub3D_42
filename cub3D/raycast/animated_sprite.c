/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:31:18 by tlasfar           #+#    #+#             */
/*   Updated: 2024/09/14 10:44:08 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

mlx_texture_t	*chose_sp_tex(t_mlx *mlx)
{
	struct timeval	current_time;
	mlx_texture_t	*tex;

	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec % 1000 < 200 && current_time.tv_sec
		- mlx->time.tv_sec < 1)
		tex = mlx->sp_tex2;
	else if (current_time.tv_usec % 1000 < 400 && current_time.tv_usec
		% 1000 >= 200 && current_time.tv_sec - mlx->time.tv_sec < 1)
		tex = mlx->sp_tex3;
	else
		tex = mlx->sp_tex1;
	return (tex);
}

void	draw_sp(t_mlx *mlx, mlx_texture_t *tex, int *co, int *data)
{
	if (tex == mlx->sp_tex1)
		mlx_put_pixel(mlx->img, co[0] + WIDTH / 2 - 255, co[1] + 2.3 * HEIGHT
			/ 4 + 20, get_pixel_color(tex, co[0] / 5, co[1], data));
	if (tex == mlx->sp_tex2)
		mlx_put_pixel(mlx->img, co[0] + WIDTH / 2 - 250, co[1] + 2.3 * HEIGHT
			/ 4 + 45, get_pixel_color(tex, co[0] / 5, co[1], data));
	if (tex == mlx->sp_tex3)
		mlx_put_pixel(mlx->img, co[0] + WIDTH / 2 - 250, co[1] + 2.3 * HEIGHT
			/ 4 + 40, get_pixel_color(tex, co[0] / 5, co[1], data));
}

void	draw_sprite(t_mlx *mlx, mlx_texture_t *tex)
{
	uint32_t	i;
	uint32_t	j;
	int			data[2];
	int			co[2];

	i = 0;
	data[0] = 0;
	data[1] = tex->height2 * 5;
	while (i < tex->width2 * 5)
	{
		j = 0;
		while (j < tex->height2 * 5)
		{
			if (get_pixel_color(tex, i / 5, j, data) != 0x00000000)
			{
				co[0] = i;
				co[1] = j;
				draw_sp(mlx, tex, co, data);
			}
			j++;
		}
		i++;
	}
}
