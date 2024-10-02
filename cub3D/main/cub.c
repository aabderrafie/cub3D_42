/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:45:35 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/26 13:33:12 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	mouse_move(void *mlx)
{
	t_mlx	*mlxx;
	int32_t	xpos;
	int32_t	ypos;
	int		center_x;

	mlxx = (t_mlx *)mlx;
	center_x = WIDTH / 2;
	mlx_get_mouse_pos(mlxx->win, &xpos, &ypos);
	mlxx->cub->s.rotation_angle -= (xpos - center_x) * 0.0018;
	mlx_set_mouse_pos(mlxx->win, WIDTH / 2, HEIGHT / 2);
	ft_render(mlxx);
}

void	mouse_press(mouse_key_t button, action_t action, modifier_key_t mods,
		void *data)
{
	t_mlx	*mlx;

	(void)mods;
	(void)button;
	mlx = (t_mlx *)data;
	if (mlx_is_mouse_down(mlx->win, 0) && action)
		gettimeofday(&mlx->time, NULL);
	if (mlx_is_mouse_down(mlx->win, 1) && action)
		check_surrounding(mlx->cub, mlx->cub->s.x, mlx->cub->s.y);
}

void	ft_mlx_hook(t_mlx *mlx)
{
	mlx_set_cursor_mode(mlx->win, 0x00034002);
	mlx_key_hook(mlx->win, key_press, mlx);
	mlx_mouse_hook(mlx->win, mouse_press, mlx);
	mlx_loop_hook(mlx->win, mouse_move, mlx);
}

void	dimension(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx->map_height = 0;
	mlx->map_width = 0;
	while (mlx->cub->map[i] != NULL)
	{
		j = 0;
		while (mlx->cub->map[i][j] != '\0')
			j++;
		if (j > mlx->map_width)
			mlx->map_width = j;
		i++;
	}
	mlx->map_height = i;
	mlx->map_height *= 32;
	mlx->map_width *= 32;
}

int	main(int ac, char **av)
{
	t_cub	*cub;
	t_mlx	*mlx;

	ft_check(ac, av[1]);
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->win = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	mlx->img = mlx_new_image(mlx->win, WIDTH, HEIGHT);
	cub = ft_calloc(1, sizeof(t_cub));
	mlx->cub = cub;
	ft_wall(cub, av[1]);
	ft_map(cub, av[1]);
	dimension(mlx);
	mlx->cub->s.x = (mlx->cub->s.x * TILE_SIZE) + TILE_SIZE / 2;
	mlx->cub->s.y = (mlx->cub->s.y * TILE_SIZE) + TILE_SIZE / 2;
	mlx->sp_tex1 = mlx_load_png("textures/sp/1.png");
	mlx->sp_tex2 = mlx_load_png("textures/sp/2.png");
	mlx->sp_tex3 = mlx_load_png("textures/sp/3.png");
	if (!mlx->sp_tex1 || !mlx->sp_tex2 || !mlx->sp_tex3)
		ft_error("Error: Failed to load sprite texture\n");
	ft_render(mlx);
	ft_mlx_hook(mlx);
	mlx_loop(mlx->win);
	return (0);
}
