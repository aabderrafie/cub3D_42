/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:53 by tlasfar           #+#    #+#             */
/*   Updated: 2024/09/14 09:49:14 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_pixel_color(mlx_texture_t *texture, int tex_x, int tex_y, int *data)
{
	uint8_t			*dst;
	unsigned int	color;

	dst = NULL;
	color = texture->pixels[0];
	tex_y = tex_y - data[0];
	if (tex_y > 0 && tex_x > 0 && (tex_y * texture->height2
			/ data[1]) < texture->height2 - 1 && tex_x < (int)texture->width2)
		dst = texture->pixels + ((tex_y * texture->height2 / data[1])
				* texture->width2 * texture->bytes_per_pixel) + (tex_x
				* texture->bytes_per_pixel);
	if (dst)
		color = (uint32_t)dst[0] << 24 
			| (uint32_t)dst[1] << 16 | (uint32_t)dst[2] << 8 | dst[3];
	return (color);
}

int	get_horizontal_texture(t_mlx *mlx, int x, int tex_y, int *data)
{
	int	tex_x;

	tex_x = 0;
	if (mlx->ray[x].angle >= 0 && mlx->ray[x].angle < M_PI)
	{
		tex_x = ((int)(mlx->ray[x].x_horz * mlx->cub->no_txt->width2 / 32)
				% mlx->cub->no_txt->width2);
		return (get_pixel_color(mlx->cub->no_txt, tex_x, tex_y, data));
	}
	else
	{
		tex_x = ((int)(mlx->ray[x].x_horz * mlx->cub->so_txt->width2 / 32)
				% mlx->cub->so_txt->width2);
		return (get_pixel_color(mlx->cub->so_txt, tex_x, tex_y, data));
	}
}

int	get_vertical_texture(t_mlx *mlx, int x, int tex_y, int *data)
{
	int	tex_x;

	tex_x = 0;
	if (mlx->ray[x].angle >= M_PI / 2 && mlx->ray[x].angle < (3 * M_PI) / 2)
	{
		tex_x = ((int)(mlx->ray[x].y_vert * mlx->cub->we_txt->width2 / 32)
				% mlx->cub->we_txt->width2);
		return (get_pixel_color(mlx->cub->we_txt, tex_x, tex_y, data));
	}
	else
	{
		tex_x = ((int)(mlx->ray[x].y_vert * mlx->cub->ea_txt->width2 / 32)
				% mlx->cub->ea_txt->width2);
		return (get_pixel_color(mlx->cub->ea_txt, tex_x, tex_y, data));
	}
}

int	get_door_texture(t_mlx *mlx, int x, int tex_y, int *data)
{
	int	tex_x;

	tex_x = 0;
	if (mlx->ray[x].hit == 'v')
		tex_x = (int)(mlx->ray[x].y_vert * mlx->cub->do_txt->width2 / 32)
			% mlx->cub->do_txt->width2;
	if (mlx->ray[x].hit == 'h')
		tex_x = (int)(mlx->ray[x].x_horz * mlx->cub->do_txt->width2 / 32)
			% mlx->cub->do_txt->width2;
	return (get_pixel_color(mlx->cub->do_txt, tex_x, tex_y, data));
}

int	get_texture_color(t_mlx *mlx, int x, int tex_y, int *data)
{
	int	color;
	int	tex_x;

	tex_x = 0;
	color = 0xFF00FFFF;
	if (mlx->ray[x].hitting_on == 'W')
	{
		if (mlx->ray[x].hit == 'h')
			color = get_horizontal_texture(mlx, x, tex_y, data);
		else if (mlx->ray[x].hit == 'v')
			color = get_vertical_texture(mlx, x, tex_y, data);
	}
	else if (mlx->ray[x].hitting_on == 'D')
		color = get_door_texture(mlx, x, tex_y, data);
	return (color);
}
