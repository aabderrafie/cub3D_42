/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:29:55 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:41:10 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	load_png(char **pos, char *line, mlx_texture_t **txt)
{
	char	*tmp;

	if (*pos != NULL)
		return ;
	tmp = *pos;
	free(tmp);
	*pos = ft_strtrim(line + 3, "\n");
	ft_check_access(*pos);
	*txt = mlx_load_png(*pos);
	if (!*txt)
		ft_error("Error: Invalid texture\n");
}

int	ft_check_lines(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split[2] != NULL)
		free_texture(split, "Error: Invalid Map\n");
	if (check_texture(split[0]) == 0)
		free_texture(split, "Error: Invalid Map\n");
	free_texture(split, NULL);
	return (1);
}

void	assign_texture(char *line, t_cub *cub)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		load_png(&cub->no, line, &cub->no_txt);
	if (ft_strncmp(line, "SO", 2) == 0)
		load_png(&cub->so, line, &cub->so_txt);
	if (ft_strncmp(line, "WE", 2) == 0)
		load_png(&cub->we, line, &cub->we_txt);
	if (ft_strncmp(line, "EA", 2) == 0)
		load_png(&cub->ea, line, &cub->ea_txt);
	if (ft_strncmp(line, "DO", 2) == 0)
		load_png(&cub->doo, line, &cub->do_txt);
	if (ft_strncmp(line, "F", 1) == 0)
		ft_color(cub->f, line + 2);
	if (ft_strncmp(line, "C", 1) == 0)
		ft_color(cub->c, line + 2);
}

void	ft_get_data(t_cub *cub, char **buff)
{
	int	i;

	i = 0;
	color_inint(cub->c);
	color_inint(cub->f);
	while (i < 7)
	{
		if (buff[i] == NULL)
			ft_error("Error: Invalid Map\n");
		ft_check_lines(buff[i]);
		assign_texture(buff[i], cub);
		i++;
	}
	if (!cub->no || !cub->so || !cub->we || !cub->ea || !cub->doo)
		free_texture(buff, "Error: Invalid Map\n");
	if (cub->f[0] == -1 || cub->c[0] == -1)
		free_texture(buff, "Error: Invalid Map\n");
	free_texture(buff, NULL);
}

void	ft_wall(t_cub *cube, char *file)
{
	t_wall	v;

	v.i = 0;
	v.fd = open(file, O_RDONLY);
	v.buffer = ft_calloc(8, sizeof(char *));
	v.line = get_next_line(v.fd);
	while (v.line && v.i < 7)
	{
		v.tmp = v.line;
		v.line = ft_strtrim(v.tmp, " \n\r\t\v\f");
		free(v.tmp);
		v.tmp = NULL;
		if (ft_strlen(v.line) > 0)
		{
			v.buffer[v.i] = ft_calloc(ft_strlen(v.line) + 1, sizeof(char));
			ft_memcpy(v.buffer[v.i], v.line, ft_strlen(v.line));
			v.i++;
		}
		free(v.line);
		v.line = NULL;
		v.line = get_next_line(v.fd);
	}
	if (v.line)
		free(v.line);
	ft_get_data(cube, v.buffer);
}
