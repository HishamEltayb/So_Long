/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_error_xpm_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:37:57 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 09:00:22 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_so_long.h"

void	error_xpm_wall(t_data *mlx);
void	error_xpm_grass(t_data *mlx);
void	error_xpm_player_left(t_data *mlx);
void	error_xpm_collectables(t_data *mlx);
void	error_xpm_player_right(t_data *mlx);

void	error_xpm_wall(t_data *mlx)
{
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mWALL.XPM FILE NOT FOUND !\033[0m\n", 38);
	exit(1);
}

void	error_xpm_grass(t_data *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->wall);
	mlx_destroy_image(mlx->connection, mlx->player_left);
	mlx_destroy_image(mlx->connection, mlx->player_right);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mGRASS.XPM FILE NOT FOUND !\033[0m\n", 39);
	exit(1);
}

void	error_xpm_collectables(t_data *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->wall);
	mlx_destroy_image(mlx->connection, mlx->player_left);
	mlx_destroy_image(mlx->connection, mlx->player_right);
	mlx_destroy_image(mlx->connection, mlx->grass);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mcollectables.XPM FILE NOT FOUND !\033[0m\n", 46);
	exit(1);
}

void	error_xpm_player_left(t_data *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->wall);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mplayer_left.XPM FILE NOT FOUND !\033[0m\n", 45);
	exit(1);
}

void	error_xpm_player_right(t_data *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->wall);
	mlx_destroy_image(mlx->connection, mlx->player_left);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mplayer_right.XPM FILE NOT FOUND !\033[0m\n", 46);
	exit(1);
}
