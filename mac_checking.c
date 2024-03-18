/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:16:52 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 08:56:31 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mac_so_long.h"

int			check_join(char *str);
static int	is_valid_map(char c);
void		check_chars_validaty(int height, int width,
				t_chars *x, t_data *mlx);

int	check_join(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			counter++;
		i++;
	}
	return (counter);
}

void	check_chars_validaty(int height, int width, t_chars *x, t_data *mlx)
{
	if ((*mlx).map[height][width] == 'C')
		(*x).collect++;
	if ((*mlx).map[height][width] == 'E')
		(*x).exit++;
	if ((*mlx).map[height][width] == 'P')
	{
		(*mlx).player_height = height;
		(*mlx).player_width = width;
		(*x).player++;
	}
	if (!is_valid_map((*mlx).map[height][width]))
		error_map_not_valid((*mlx).map);
}

static	int	is_valid_map(char c)
{
	return (c == 'C' || c == 'E' || c == '0' || c == '1' || c == 'P');
}
