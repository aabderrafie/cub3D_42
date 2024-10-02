/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:31:40 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:42:12 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	ft_check_access(char *s)
{
	if (open(s, O_RDONLY, 0644) == -1)
	{
		free(s);
		ft_error("Error: File does not exist\n");
	}
	if (ft_strncmp(s + ft_strlen(s) - 4, ".png", 4) != 0)
	{
		free(s);
		ft_error("Error: Invalid texture file\n");
	}
}

void	ft_check(int c, char *s)
{
	char	*tmp;

	if (c != 2)
		ft_error("Usage: ./cub3d <map.cub>\n");
	if (ft_strncmp(s + ft_strlen(s) - 4, ".cub", 4))
		ft_error("Error: Invalid extension\n");
	if (open(s, O_RDONLY, 0644) == -1)
		ft_error("Error: File does not exist\n");
	tmp = get_next_line(open(s, O_RDONLY));
	if (tmp == NULL)
		return (ft_error("Error: Empty file\n"));
	free(tmp);
}
