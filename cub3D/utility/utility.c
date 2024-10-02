/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:39:57 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:59:40 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_tile(t_mlx *mlx)
{
	int	x;
	int	y;

	x = (int)mlx->cub->s.x / TILE_SIZE;
	y = (int)mlx->cub->s.y / TILE_SIZE;
	if (mlx->cub->map[y][x] == '1')
		return (1);
	if (mlx->cub->map[y][x] == 'D' && check_if_open(mlx->cub, mlx->cub->s.x,
			mlx->cub->s.y) == 0)
		return (1);
	return (0);
}

void	free_texture(char **lines, char *message)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	if (message)
		ft_error(message);
}

int	check_texture(char *line)
{
	if ((ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "WE", 2) == 0
			|| ft_strncmp(line, "EA", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "DO", 2) == 0) && ft_strlen(line) == 2)
		return (1);
	if ((ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		&& ft_strlen(line) == 1)
		return (1);
	return (0);
}

void	spread(t_cub *cube, double x, double y)
{
	if ((cube->map[(int)x][(int)y + 1] == '0') || ((cube->map[(int)x][(int)y
				+ 1] == 'D') && cube->map[(int)x][(int)y] != 'D'))
		double_fill(cube, x, y + 1);
	if ((y > 0 && cube->map[(int)x][(int)y - 1] == '0') || (y > 0
			&& (cube->map[(int)x][(int)y - 1] == 'D')
			&& cube->map[(int)x][(int)y] != 'D'))
		double_fill(cube, x, y - 1);
	if ((x < ft_arrsize(cube->map) - 1 && cube->map[(int)x + 1][(int)y] == '0')
		|| (x < ft_arrsize(cube->map) - 1 && (cube->map[(int)x
				+ 1][(int)y] == 'D') && cube->map[(int)x][(int)y] != 'D'))
		double_fill(cube, x + 1, y);
	if ((cube->map[(int)x - 1][(int)y] == '0') || ((cube->map[(int)x
				- 1][(int)y] == 'D') && cube->map[(int)x][(int)y] != 'D'))
		double_fill(cube, x - 1, (int)y);
}
