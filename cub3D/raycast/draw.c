/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:10:19 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/26 12:45:41 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_direction	set_direction(double angle)
{
	t_direction	d;

	d.is_up = angle > 0 && angle < M_PI;
	d.is_down = !d.is_up;
	d.is_right = angle < 0.5 * M_PI || angle > 1.5 * M_PI;
	d.is_left = !d.is_right;
	return (d);
}

double	get_min(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	ft_distance(t_mlx *mlx)
{
	double	theta;
	double	increment;
	int		i;

	if (mlx->ray)
		free(mlx->ray);
	mlx->ray = ft_calloc(NUM_RAYS, sizeof(t_ray));
	theta = mlx->cub->s.rotation_angle - (FOV_ANGLE / 2);
	increment = (FOV_ANGLE) / NUM_RAYS;
	i = 0;
	while (i < NUM_RAYS)
	{
		mlx->ray[i].hitting_on = 'W';
		mlx->ray[i].animated_sp = false;
		mlx->ray[i].sp_hit = 'N';
		mlx->ray[i].x = 0;
		theta = normalize_angle(theta);
		get_vertical(mlx, theta, i);
		get_horizontal(mlx, theta, i);
		calculate_distance(mlx, i);
		theta += increment;
		i++;
	}
}

void	calculate_distance(t_mlx *mlx, int i)
{
	double	dv;
	double	dh;

	dv = sqrt(pow(mlx->cub->s.x - mlx->ray[i].x_vert, 2) + pow(mlx->cub->s.y
				- mlx->ray[i].y_vert, 2));
	dh = sqrt(pow(mlx->cub->s.x - mlx->ray[i].x_horz, 2) + pow(mlx->cub->s.y
				- mlx->ray[i].y_horz, 2));
	if (dv <= dh)
	{
		mlx->ray[i].hit = 'v';
		if (mlx->ray[i].v_hitting_on == 'D')
			mlx->ray[i].hitting_on = mlx->ray[i].v_hitting_on;
		mlx->ray[i].distance = dv;
		mlx->ray[i].x = mlx->ray[i].x_vert;
		mlx->ray[i].y = mlx->ray[i].y_vert;
	}
	else
	{
		mlx->ray[i].hit = 'h';
		if (mlx->ray[i].h_hitting_on == 'D')
			mlx->ray[i].hitting_on = mlx->ray[i].h_hitting_on;
		mlx->ray[i].distance = dh;
		mlx->ray[i].x = mlx->ray[i].x_horz;
		mlx->ray[i].y = mlx->ray[i].y_horz;
	}
}
