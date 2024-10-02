/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:54 by tlasfar           #+#    #+#             */
/*   Updated: 2024/09/14 09:50:05 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	double_fill(t_cub *cube, double x, double y)
{
	if (cube->map[(int)x][(int)y] == '1')
		return ;
	if ((x == 0 || y == 0 || y == (int)ft_strlen(cube->map[(int)x]) - 1
			|| x == ft_arrsize(cube->map) - 1 || (x < ft_arrsize(cube->map)
				&& cube->map[(int)(x) + 1][(int)y] == ' ')
			|| cube->map[(int)(x)][(int)y + 1] == ' '
			|| cube->map[(int)x][(int)y - 1] == ' ' || cube->map[(int)(x)
			+ 1][(int)y] == ' '
			|| ((int)ft_strlen(cube->map[(int)(x)-1]) 
				<= (int)ft_strlen(cube->map[(int)(x)])
				&& (int)ft_strlen(cube->map[(int)(x)-1]) <= (int)y)
			|| cube->map[(int)(x)-1][(int)y] == ' ')
		|| (cube->map[(int)(x)][(int)y] != 'D'
			&& cube->map[(int)(x)][(int)y] != '0'
			&& cube->map[(int)(x)][(int)y] != 'N'
			&& cube->map[(int)(x)][(int)y] != 'S'
			&& cube->map[(int)(x)][(int)y] != 'W'
			&& cube->map[(int)(x)][(int)y] != 'E'))
		ft_error("Invalid map\n");
	if (cube->map[(int)x][(int)y] != 'D')
		cube->map[(int)x][(int)y] = 'F';
	spread(cube, x, y);
}

int	found_a_player(t_cub *cube, int i, int j)
{
	cube->s.y = i;
	cube->s.x = j;
	cube->s.dir = cube->map[i][j];
	if (cube->s.dir == 'N')
		cube->s.rotation_angle = M_PI / 2;
	else if (cube->s.dir == 'S')
		cube->s.rotation_angle = 3 * (M_PI / 2);
	else if (cube->s.dir == 'W')
		cube->s.rotation_angle = M_PI;
	else if (cube->s.dir == 'E')
		cube->s.rotation_angle = 0;
	cube->s.move_speed = 3.0;
	cube->s.rotation_speed = 3 * (M_PI / 180);
	cube->s.turn_direction = 0;
	cube->s.walk_direction = 0;
	return (1);
}

void	check_map_chars(t_cub *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (cube->map[y])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (cube->map[y][x] != '1' && cube->map[y][x] != '0'
				&& cube->map[y][x] != 'N' && cube->map[y][x] != 'S'
				&& cube->map[y][x] != 'W' && cube->map[y][x] != 'E'
				&& cube->map[y][x] != ' ' && cube->map[y][x] != 'D')
				ft_error("Invalid character in map\n");
			x++;
		}
		y++;
	}
}

void	check_map(t_cub *cube)
{
	int	player_count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	player_count = 0;
	check_map_chars(cube);
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
				|| cube->map[i][j] == 'W' || cube->map[i][j] == 'E')
				player_count += found_a_player(cube, i, j);
			if (cube->map[i][j] == 'D')
				handle_door(cube, i, j);
			j++;
		}
		i++;
	}
	check_player_and_fill(cube, player_count);
}

void	ft_map(t_cub *cube, char *file)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;
	char	**parts;

	fd = open(file, O_RDONLY);
	line = ft_strdup("");
	while (line)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = line;
		line = ft_strjoin(line, tmp);
		free(tmp);
		free(tmp2);
	}
	parts = ft_split(line, '\n');
	free(line);
	cube->map = extract_map(parts);
	if (ft_arrsize(cube->map) < ft_arrsize(parts) - 7)
		ft_error("Invalid map\n");
	check_map(cube);
}
