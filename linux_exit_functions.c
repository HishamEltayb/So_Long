/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_exit_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:43:58 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 09:00:24 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_so_long.h"

int		is_valid_char(char c);
void	exit_win(t_data *mlx);
int		exit_mouse(t_data *mlx);
void	error_xpm_exit(t_data *mlx);
int		exit_key(int key, t_data *mlx);

int	exit_mouse(t_data *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->wall);
	mlx_destroy_image(mlx->connection, mlx->player_left);
	mlx_destroy_image(mlx->connection, mlx->player_right);
	mlx_destroy_image(mlx->connection, mlx->grass);
	mlx_destroy_image(mlx->connection, mlx->coins);
	mlx_destroy_image(mlx->connection, mlx->exit);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(1, "\033[1;34m(MOUSE) BYE! \033[0m🥺\n", 29);
	exit(0);
}

void	exit_win(t_data *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->wall);
	mlx_destroy_image(mlx->connection, mlx->player_left);
	mlx_destroy_image(mlx->connection, mlx->player_right);
	mlx_destroy_image(mlx->connection, mlx->grass);
	mlx_destroy_image(mlx->connection, mlx->coins);
	mlx_destroy_image(mlx->connection, mlx->exit);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(1, "\n\033[1;33mYOU WON !\033[0m 🥳\n\n", 28);
	exit(0);
}

int	exit_key(int key, t_data *mlx)
{
	if (key == 65307)
	{
		mlx_destroy_image(mlx->connection, mlx->wall);
		mlx_destroy_image(mlx->connection, mlx->player_left);
		mlx_destroy_image(mlx->connection, mlx->player_right);
		mlx_destroy_image(mlx->connection, mlx->grass);
		mlx_destroy_image(mlx->connection, mlx->coins);
		mlx_destroy_image(mlx->connection, mlx->exit);
		mlx_destroy_window(mlx->connection, mlx->window);
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		free_split(mlx->map);
		write(1, "\033[1;34m(KEYBOARD) BYE! \033[0m🥺\n", 32);
		exit(0);
	}
	return (0);
}

void	error_xpm_exit(t_data *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->wall);
	mlx_destroy_image(mlx->connection, mlx->player_left);
	mlx_destroy_image(mlx->connection, mlx->player_right);
	mlx_destroy_image(mlx->connection, mlx->grass);
	mlx_destroy_image(mlx->connection, mlx->coins);
	mlx_destroy_window(mlx->connection, mlx->window);
	mlx_destroy_display(mlx->connection);
	free(mlx->connection);
	free_split(mlx->map);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mEXIT.XPM FILE NOT FOUND !\033[0m\n", 38);
	exit(1);
}

int	is_valid_char(char c)
{
	return (c == 'C' || c == 'E' || c == '0');
}
