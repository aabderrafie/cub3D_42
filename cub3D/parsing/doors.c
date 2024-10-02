/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasfar <tlasfar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:32:21 by tlasfar           #+#    #+#             */
/*   Updated: 2024/09/13 23:51:14 by tlasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char	get_door_direction(t_cub *cube, int i, int j)
{
	if (cube->map[i + 1][j] != '1' && cube->map[i - 1][j] != '1'
		&& cube->map[i][j + 1] == '1' && cube->map[i][j - 1] == '1')
		return ('V');
	if (cube->map[i][j + 1] != '1' && cube->map[i][j - 1] != '1' && cube->map[i
		+ 1][j] == '1' && cube->map[i - 1][j] == '1')
		return ('H');
	return ('I');
}

void	add_door(t_cub *cube, t_door *door)
{
	t_door	*tmp;

	if (cube->door == NULL)
	{
		cube->door = door;
		door->next = NULL;
	}
	else
	{
		tmp = cube->door;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = door;
		door->next = NULL;
	}
}

void	handle_door(t_cub *cube, int i, int j)
{
	t_door	*door;

	cube->door_count++;
	door = (t_door *)malloc(sizeof(t_door));
	if (!door)
		ft_error("Error: malloc failed\n");
	door->direction = get_door_direction(cube, i, j);
	if (door->direction == 'I')
		ft_error("Error: Invalid door\n");
	door->x = j;
	door->y = i;
	door->opening_persentage = 0;
	door->is_open = false;
	add_door(cube, door);
}
