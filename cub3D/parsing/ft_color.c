/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:31:08 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:42:27 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	color_inint(int *color)
{
	color[0] = -1;
	color[1] = -1;
	color[2] = -1;
}

void	ft_color(int *color, char *s)
{
	char	**tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strtrim(s, " \n\r\t\v\f");
	tmp = ft_split(tmp2, ',');
	free(tmp2);
	while (i < 3)
	{
		if (!ft_isnbr(tmp[i]))
			free_texture(tmp, "Error: Invalid color value \n");
		color[i] = ft_atoi(tmp[i]);
		if (color[i] < 0 || color[i] > 255)
			free_texture(tmp,
				"Error: Color values must be between 0 and 255\n");
		i++;
	}
	if (tmp[3])
		free_texture(tmp, "Error: Extra color value\n");
	free_texture(tmp, NULL);
}
