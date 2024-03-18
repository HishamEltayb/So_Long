/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_image_movements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:03:16 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 09:00:30 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_so_long.h"

int		render(t_data *mlx);
int		move_image(int key, t_data *mlx);
void	movements_of_player(int key, int flag, t_data *mlx);
void	movements(int key, int height, int width, t_data *mlx);

// sleep(2);
// mlx_clear_window(mlx->connection, mlx->window);
//should be after line 98 in linux if the render is bad
void	movements(int key, int height, int width, t_data *mlx)
{
	if ((key == 65364) && (height < mlx->height))
		if (is_valid_char((*mlx).map[height + 1][width]))
			movement_down(height, width, mlx);
	if ((key == 65362) && (height > 0))
		if (is_valid_char((*mlx).map[height - 1][width]))
			movement_up(height, width, mlx);
	if ((key == 65363) && (width < mlx->width))
		if (is_valid_char((*mlx).map[height][width + 1]))
			movement_right(height, width, mlx);
	if ((key == 65361) && (width > 0))
		if (is_valid_char((*mlx).map[height][width - 1]))
			movement_left(height, width, mlx);
}

void	movements_of_player(int key, int flag, t_data *mlx)
{
	int			height;
	int			width;

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
	if (key == 65307)
		exit_key(65307, mlx);
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
