/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_player_movements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:40:07 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 08:56:59 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mac_so_long.h"

void	print_steps(int steps);
void	movement_up(int height, int width, t_data *mlx);
void	movement_left(int height, int width, t_data *mlx);
void	movement_down(int height, int width, t_data *mlx);
void	movement_right(int height, int width, t_data *mlx);

void	movement_up(int height, int width, t_data *mlx)
{
	if (mlx->number_of_coins == 0 && (*mlx).map[height - 1][width] == 'E')
		exit_win(mlx);
	if ((*mlx).map[height - 1][width] == 'C')
		(*mlx).number_of_coins--;
	if ((*mlx).map[height - 1][width] == 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).player_on_exit = 1;
	}
	else if ((*mlx).map[height][width] == 'E')
	{
		if ((*mlx).map[height - 1][width] != '1')
			(*mlx).player_on_exit = 0;
		(*mlx).map[height - 1][width] = 'P';
	}
	else if ((*mlx).map[height - 1][width] != 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).map[height - 1][width] = 'P';
	}
	print_steps(++((*mlx).steps));
}

void	movement_left(int height, int width, t_data *mlx)
{
	(*mlx).player_direction = 1;
	if (mlx->number_of_coins == 0 && (*mlx).map[height][width - 1] == 'E')
		exit_win(mlx);
	if ((*mlx).map[height][width - 1] == 'C')
		(*mlx).number_of_coins--;
	if ((*mlx).map[height][width - 1] == 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).player_on_exit = 1;
	}
	else if ((*mlx).map[height][width] == 'E')
	{
		if ((*mlx).map[height][width - 1] != '1')
			(*mlx).player_on_exit = 0;
		(*mlx).map[height][width - 1] = 'P';
	}
	else if ((*mlx).map[height][width - 1] != 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).map[height][width - 1] = 'P';
	}
	print_steps(++((*mlx).steps));
}

void	movement_down(int height, int width, t_data *mlx)
{
	if (mlx->number_of_coins == 0 && (*mlx).map[height + 1][width] == 'E')
		exit_win(mlx);
	if ((*mlx).map[height + 1][width] == 'C')
		(*mlx).number_of_coins--;
	if ((*mlx).map[height + 1][width] == 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).player_on_exit = 1;
	}
	else if ((*mlx).map[height][width] == 'E')
	{
		if ((*mlx).map[height + 1][width] != '1')
			(*mlx).player_on_exit = 0;
		(*mlx).map[height + 1][width] = 'P';
	}
	else if ((*mlx).map[height + 1][width] != 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).map[height + 1][width] = 'P';
	}
	print_steps(++((*mlx).steps));
}

void	movement_right(int height, int width, t_data *mlx)
{
	(*mlx).player_direction = 0;
	if (mlx->number_of_coins == 0 && (*mlx).map[height][width + 1] == 'E')
		exit_win(mlx);
	if ((*mlx).map[height][width + 1] == 'C')
		(*mlx).number_of_coins--;
	if ((*mlx).map[height][width + 1] == 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).player_on_exit = 1;
	}
	else if ((*mlx).map[height][width] == 'E')
	{
		if ((*mlx).map[height][width + 1] != '1')
			(*mlx).player_on_exit = 0;
		(*mlx).map[height][width + 1] = 'P';
	}
	else if ((*mlx).map[height][width + 1] != 'E')
	{
		(*mlx).map[height][width] = '0';
		(*mlx).map[height][width + 1] = 'P';
	}
	print_steps(++((*mlx).steps));
}

void	print_steps(int steps)
{
	write(1, "steps[", 6);
	ft_putnbr_fd(steps, 1);
	write(1, "]\n", 2);
}
