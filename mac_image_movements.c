/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_image_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:03:16 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 08:56:53 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mac_so_long.h"

int		render(t_data *mlx);
int		move_image(int key, t_data *mlx);
void	movements_of_player(int key, int flag, t_data *mlx);
void	movements(int key, int height, int width, t_data *mlx);

void	movements(int key, int height, int width, t_data *mlx)
{
	if ((key == 125 || key == 1) && (height < mlx->height))
		if (is_valid_char((*mlx).map[height + 1][width]))
			movement_down(height, width, mlx);
	if ((key == 126 || key == 13) && (height > 0))
		if (is_valid_char((*mlx).map[height - 1][width]))
			movement_up(height, width, mlx);
	if ((key == 124 || key == 2) && (width < mlx->width))
		if (is_valid_char((*mlx).map[height][width + 1]))
			movement_right(height, width, mlx);
	if ((key == 123 || key == 0) && (width > 0))
		if (is_valid_char((*mlx).map[height][width - 1]))
			movement_left(height, width, mlx);
}

void	movements_of_player(int key, int flag, t_data *mlx)
{
	int	height;
	int	width;

	height = -1;
	while ((*mlx).map[++height] && !flag)
	{
		width = -1;
		flag = 0;
		while ((*mlx).map[height][++width])
		{
			if ((*mlx).map[height][width] == 'E')
			{
				movements(key, height, width, mlx);
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
	if (key == 53)
		exit_key(53, mlx);
}

int	move_image(int key, t_data *mlx)
{
	int			height;
	int			width;
	int			flag;

	height = -1;
	while ((*mlx).map[++height])
	{
		width = -1;
		flag = 0;
		while ((*mlx).map[height][++width])
		{
			if ((*mlx).map[height][width] == 'P')
			{
				movements(key, height, width, mlx);
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
	movements_of_player(key, flag, mlx);
	return (0);
}

int	render(t_data *mlx)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	mlx_clear_window(mlx->connection, mlx->window);
	while (mlx->map[height] && height < mlx->height)
	{
		while (mlx->map[height][width] && width < mlx->width)
		{
			putting_image_to_window(mlx, height, width);
			width++;
		}
		width = 0;
		height++;
	}
	return (0);
}
