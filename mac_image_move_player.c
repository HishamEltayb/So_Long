/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_image_move_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:38:05 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 08:56:49 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mac_so_long.h"

void	player_on_exit_move(t_data *mlx, int height, int width);
void	player_not_on_exit_move(t_data *mlx, int height, int width);
void	putting_image_to_window(t_data *mlx, int height, int width);

void	player_on_exit_move(t_data *mlx, int height, int width)
{
	if (mlx->map[height][width] == '1')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->wall, width * mlx->pixel, height * mlx->pixel);
	if (mlx->map[height][width] != '1')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->grass, width * mlx->pixel, height * mlx->pixel);
	if (mlx->map[height][width] == 'E')
	{
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->exit, width * mlx->pixel, height * mlx->pixel);
		if (mlx->player_direction == 1)
			mlx_put_image_to_window(mlx->connection, mlx->window,
				mlx->player_left, width * mlx->pixel, height * mlx->pixel);
		else
			mlx_put_image_to_window(mlx->connection, mlx->window,
				mlx->player_right, width * mlx->pixel, height * mlx->pixel);
	}
	if (mlx->map[height][width] == 'C')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->coins, width * mlx->pixel, height * mlx->pixel);
}

void	player_not_on_exit_move(t_data *mlx, int height, int width)
{
	if (mlx->map[height][width] == '1')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->wall, width * mlx->pixel, height * mlx->pixel);
	if (mlx->map[height][width] != '1')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->grass, width * mlx->pixel, height * mlx->pixel);
	if (mlx->map[height][width] == 'E')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->exit, width * mlx->pixel, height * mlx->pixel);
	if (mlx->map[height][width] == 'P')
	{
		if (mlx->player_direction == 1)
			mlx_put_image_to_window(mlx->connection, mlx->window,
				mlx->player_left, width * mlx->pixel, height * mlx->pixel);
		else
			mlx_put_image_to_window(mlx->connection, mlx->window,
				mlx->player_right, width * mlx->pixel, height * mlx->pixel);
	}
	if (mlx->map[height][width] == 'C')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			mlx->coins, width * mlx->pixel, height * mlx->pixel);
}

void	putting_image_to_window(t_data *mlx, int height, int width)
{
	if (mlx->player_on_exit)
		player_on_exit_move(mlx, height, width);
	else if (!mlx->player_on_exit)
		player_not_on_exit_move(mlx, height, width);
}
