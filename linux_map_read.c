/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_map_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:33 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 09:00:35 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_so_long.h"

char	*read_map(char *arg);
void	free_split(char **str);
void	check_walls(t_data *mlx);
void	check_map_name(char *arg);
char	*parsing_the_map(int fd, char **join);

char	*read_map(char *arg)
{
	int		fd;
	char	*join;

	join = NULL;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		error_map_not_found();
	parsing_the_map(fd, &join);
	close(fd);
	return (join);
}

char	*parsing_the_map(int fd, char **join)
{
	int		letter;
	char	*str;
	char	*temp;

	str = malloc(2);
	if (!str)
		exit(1);
	ft_bzero(str, 2);
	letter = read(fd, str, 1);
	if (letter <= 0)
	{
		close(fd);
		error_map_empty(str);
	}
	while (letter > 0)
	{
		temp = (*join);
		(*join) = ft_strjoin(temp, str);
		if (!*join)
			error_joining(str, temp);
		free(temp);
		ft_bzero(str, 2);
		letter = read(fd, str, 1);
		if (letter < 0)
			error_map_read(str);
	}
	free(str);
	return (*join);
}

void	check_map_name(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	i -= 4;
	if (ft_strncmp(arg + i, ".ber", 4))
		error_map_wrong_name();
}

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	check_walls(t_data *mlx)
{
	int	height;
	int	width;

	height = -1;
	while ((*mlx).map[++height])
	{
		width = -1;
		while ((*mlx).map[height][++width])
		{
			if ((*mlx).map[height][0] != '1' || (*mlx).map[0][width] != '1'
			|| (*mlx).map[height][(mlx->width - 1)] != '1'
			|| (*mlx).map[(mlx->height - 1)][width] != '1')
				error_map_walls((*mlx).map);
		}
	}
}
