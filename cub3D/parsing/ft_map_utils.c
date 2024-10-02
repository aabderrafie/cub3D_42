/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasfar <tlasfar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:12:19 by tlasfar           #+#    #+#             */
/*   Updated: 2024/09/12 16:55:23 by tlasfar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**extract_map(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		if (parts[i][0] == '1' || parts[i][0] == ' ' || parts[i][0] == '0')
			break ;
		i++;
	}
	return (parts + i);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	ft_arrsize(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

void	check_player_and_fill(t_cub *cube, int player_count)
{
	if (player_count == 1)
		double_fill(cube, cube->s.y, cube->s.x);
	else
	{
		dprintf(2, "Error: Something is wrong with the player\n");
		exit(76);
	}
}
