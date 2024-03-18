/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:24:41 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 09:00:38 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_so_long.h"

int		main(int ac, char **av);
void	game_initilize(t_data *mlx);
void	image_initilize(t_data *mlx);
void	validpath(t_data *mlx, int x, int y);
int		is_validpath(t_data *mlx, int x, int y);

int	main(int ac, char **av)
{
	t_data	mlx;

	if (ac < 2)
		error_short_arguments();
	if (ac > 2)
		error_too_much_arguments();
	if (ac == 2)
	{
		map_initilize(av[1], &mlx);
		validpath(&mlx, mlx.player_width, mlx.player_height);
		mlx.player_direction = 1;
		free_split(mlx.map_copy);
		if (!mlx.is_valid)
			error_map_invalid_path(mlx.map);
		game_initilize(&mlx);
	}
	return (0);
}

int	is_validpath(t_data *mlx, int width, int height)
{
	int		i;
	int		j;

	i = 1;
	if ((*mlx).map_copy[height][width] != '1')
	{
		(*mlx).map_copy[height][width] = '1';
		while ((*mlx).map[i] && i < (*mlx).height - 1)
		{
			j = 1;
			while ((*mlx).map_copy[i][j] && (*mlx).map_copy[i][j] != '\n')
			{
				if ((*mlx).map_copy[i][j] == 'E'
					|| (*mlx).map_copy[i][j] == 'C')
					return (1);
				j++;
			}
			i++;
		}
		(*mlx).is_valid = 1;
	}
	return (0);
}

void	validpath(t_data *mlx, int width, int height)
{
	(*mlx).map_copy[height][width] = '1';
	if (!(*mlx).is_valid && is_validpath(mlx, width, height - 1))
		validpath(mlx, width, height - 1);
	if (!(*mlx).is_valid && is_validpath(mlx, width + 1, height))
		validpath(mlx, width + 1, height);
	if (!(*mlx).is_valid && is_validpath(mlx, width, height + 1))
		validpath(mlx, width, height + 1);
	if (!(*mlx).is_valid && is_validpath(mlx, width - 1, height))
		validpath(mlx, width - 1, height);
}

void	game_initilize(t_data *mlx)
{
	int	len;

	(*mlx).connection = mlx_init();
	(*mlx).window = mlx_new_window((*mlx).connection, (*mlx).width
			* (*mlx).pixel, (*mlx).height * (*mlx).pixel, "so_long");
	(*mlx).wall = mlx_xpm_file_to_image((*mlx).connection,
			"textures/wall.xpm", &len, &len);
	if (!(*mlx).wall)
		error_xpm_wall(mlx);
	image_initilize(mlx);
	mlx_hook((*mlx).window, ON_KEYDOWN, 1L << 0, move_image, mlx);
	mlx_loop_hook((*mlx).connection, render, mlx);
	mlx_hook((*mlx).window, ON_DESTROY, 1L << 3, exit_mouse, mlx);
	mlx_loop((*mlx).connection);
}

void	image_initilize(t_data *mlx)
{
	int	len;

	(*mlx).player_left = mlx_xpm_file_to_image((*mlx).connection,
			"textures/player_left.xpm", &len, &len);
	if (!(*mlx).player_left)
		error_xpm_player_left(mlx);
	(*mlx).player_right = mlx_xpm_file_to_image((*mlx).connection,
			"textures/player_right.xpm", &len, &len);
	if (!(*mlx).player_right)
		error_xpm_player_right(mlx);
	(*mlx).grass = mlx_xpm_file_to_image((*mlx).connection,
			"textures/grass.xpm", &len, &len);
	if (!(*mlx).grass)
		error_xpm_grass(mlx);
	(*mlx).coins = mlx_xpm_file_to_image((*mlx).connection,
			"textures/collectables.xpm", &len, &len);
	if (!(*mlx).coins)
		error_xpm_collectables(mlx);
	(*mlx).exit = mlx_xpm_file_to_image((*mlx).connection,
			"textures/exit.xpm", &len, &len);
	if (!(*mlx).exit)
		error_xpm_exit(mlx);
}
