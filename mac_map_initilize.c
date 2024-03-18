/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_map_initilize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:33 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 08:56:55 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mac_so_long.h"

int			number_of_coins(t_data *mlx);
int			check_map_rectangular(t_data *mlx);
void		map_initilize(char *arg, t_data *mlx);

void	map_initilize(char *arg, t_data *mlx)
{
	char	*join;
	int		counter;

	(*mlx).pixel = 50;
	(*mlx).steps = 0;
	(*mlx).is_valid = 0;
	(*mlx).player_on_exit = 0;
	check_map_name(arg);
	join = read_map(arg);
	(*mlx).map = ft_split(join, '\n');
	if (!(*mlx).map)
		error_split(join);
	counter = check_join(join);
	free(join);
	(*mlx).height = check_map_rectangular(mlx);
	if ((*mlx).height <= counter)
		error_newline((*mlx).map);
	(*mlx).width = ft_strlen((*mlx).map[0]);
	check_walls(mlx);
	(*mlx).number_of_coins = number_of_coins(mlx);
	join = read_map(arg);
	(*mlx).map_copy = ft_split(join, '\n');
	if (!(*mlx).map_copy)
		error_split(join);
	free(join);
}

int	number_of_coins(t_data *mlx)
{
	int		height;
	int		width;
	t_chars	x;

	x.collect = 0;
	x.player = 0;
	x.exit = 0;
	height = -1;
	while ((*mlx).map[++height])
	{
		width = -1;
		while ((*mlx).map[height][++width])
			check_chars_validaty(height, width, &x, mlx);
	}
	if (x.exit != 1)
		error_more_than_exit((*mlx).map);
	if (x.player != 1)
		error_more_than_player((*mlx).map);
	if (x.collect < 1)
		error_no_collectables((*mlx).map);
	return (x.collect);
}

int	check_map_rectangular(t_data *mlx)
{
	int		height;
	int		width;
	size_t	column;

	height = 0;
	while ((*mlx).map[height])
		height++;
	if (height > 28)
		error_map_bigger_than_screen((*mlx).map);
	width = 0;
	while (++width < (height - 1))
	{
		column = ft_strlen((*mlx).map[width - 1]);
		if (column > 52)
			error_map_bigger_than_screen((*mlx).map);
		if (ft_strlen((*mlx).map[width]) == column)
			continue ;
		else
			error_map_not_rectangular((*mlx).map);
	}
	return (height);
}
