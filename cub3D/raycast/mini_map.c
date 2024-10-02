/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:49:48 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:31:49 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	has_wall_at(t_mlx *mlx, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x / TILE_SIZE);
	map_y = (int)floor(y / TILE_SIZE);
	if (x < 0 || x > mlx->map_width || y < 0 || y > mlx->map_height)
		return (0);
	if (map_y >= ft_arrsize(mlx->cub->map)
		|| map_x >= (int)ft_strlen(mlx->cub->map[map_y]))
		return (0);
	if (mlx->cub->map[map_y][map_x] == '1')
		return (1);
	if (mlx->cub->map[map_y][map_x] == 'D' && !check_if_open(mlx->cub, x, y))
		return (2);
	return (0);
}

void	draw_map_background(t_mlx *mlx, t_mini_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height + 20)
	{
		j = 0;
		while (j < map->map_width + 20)
		{
			ft_put_in(j, i, mlx->img, 0x000000ff);
			j++;
		}
		i++;
	}
}

void	mini_map_init(t_mlx *mlx, t_mini_map *map)
{
	map->map_width = 300;
	map->map_height = 300;
	map->x_start = mlx->cub->s.x - 150;
	map->y_start = mlx->cub->s.y - 150;
	map->x_end = mlx->cub->s.x + 150;
	map->y_end = mlx->cub->s.y + 150;
	map->y = floor(map->y_start);
	map->x = floor(map->x_start);
	draw_map_background(mlx, map);
}

void	mini_map(t_mlx *mlx)
{
	t_mini_map	map;

	mini_map_init(mlx, &map);
	while (map.y < map.y_end)
	{
		map.x = (map.x_start);
		map.x = floor(map.x_start);
		while (map.x < map.x_end)
		{
			map.x1 = map.x - mlx->cub->s.x + map.map_width / 2;
			map.y1 = map.y - mlx->cub->s.y + map.map_height / 2;
			if (has_wall_at(mlx, map.x, map.y) == 1)
				ft_put_in(map.x1 + 10, map.y1 + 10, mlx->img, 0xc44900ff);
			else if (has_wall_at(mlx, map.x, map.y) == 2)
				ft_put_in(map.x1 + 10, map.y1 + 10, mlx->img, 0x91feaaAA);
			else
				ft_put_in(map.x1 + 10, map.y1 + 10, mlx->img, 0x136f63ff);
			map.x++;
		}
		map.y++;
	}
	ft_put_in(150, 150, mlx->img, 0x80ed99ff);
}
