/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:09:23 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:51:02 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_if_open(t_cub *cub, double x, double y)
{
	t_door	*door;

	door = cub->door;
	while (door)
	{
		if (door->x == (int)x / TILE_SIZE && door->y == (int)y / TILE_SIZE)
			return (door->is_open);
		door = door->next;
	}
	return (0);
}

int	check_orthogonal(t_cub *cub, t_door *door, int x, int y)
{
	double	player_ang;

	player_ang = normalize_angle(cub->s.rotation_angle);
	if ((x / TILE_SIZE == door->x && y / TILE_SIZE == door->y + 1
			&& player_ang >= M_PI / 4 && player_ang <= 3 * M_PI / 4) || (x
			/ TILE_SIZE == door->x && y / TILE_SIZE == door->y - 1
			&& player_ang >= 5 * M_PI / 4 && player_ang <= 7 * M_PI / 4) || (y
			/ TILE_SIZE == door->y && x / TILE_SIZE == door->x + 1
			&& player_ang >= 3 * M_PI / 4 && player_ang <= 5 * M_PI / 4) || (y
			/ TILE_SIZE == door->y && x / TILE_SIZE == door->x - 1
			&& ((player_ang >= 7 * M_PI / 4 && player_ang <= 2 * M_PI)
				|| (player_ang >= 0 && player_ang <= M_PI / 4))))
	{
		return (1);
	}
	return (0);
}

int	check_diagonal(t_cub *cub, t_door *door, int x, int y)
{
	double	player_ang;

	player_ang = normalize_angle(cub->s.rotation_angle);
	if ((x / TILE_SIZE == door->x + 1 && y / TILE_SIZE == door->y + 1
			&& player_ang >= M_PI / 2 && player_ang <= M_PI) || (x
			/ TILE_SIZE == door->x - 1 && y / TILE_SIZE == door->y + 1
			&& player_ang >= 0 && player_ang <= M_PI / 2) || (y
			/ TILE_SIZE == door->y - 1 && x / TILE_SIZE == door->x - 1
			&& player_ang >= 3 * M_PI / 2 && player_ang <= 2 * M_PI) || (y
			/ TILE_SIZE == door->y - 1 && x / TILE_SIZE == door->x + 1
			&& ((player_ang >= M_PI && player_ang <= 3 * M_PI / 2))))
	{
		return (1);
	}
	return (0);
}

void	open_the_door(t_door *door, t_mlx *mlx)
{
	if (!door->is_open)
	{
		door->opening_persentage = 0;
		while (door->opening_persentage < 32)
		{
			door->opening_persentage += 1;
			ft_render(mlx);
		}
	}
	else
	{
		door->opening_persentage = 32;
		while (door->opening_persentage > 0)
		{
			door->opening_persentage -= 1;
			ft_render(mlx);
		}
	}
}

void	check_surrounding(t_cub *cub, int x, int y)
{
	double	player_ang;
	t_door	*door;

	player_ang = normalize_angle(cub->s.rotation_angle);
	door = cub->door;
	while (door)
	{
		if (check_orthogonal(cub, door, x, y) || check_diagonal(cub, door, x,
				y))
		{
			door->is_open = !door->is_open;
			return ;
		}
		door = door->next;
	}
}
