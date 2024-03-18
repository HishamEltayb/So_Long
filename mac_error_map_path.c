/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_error_map_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:10 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 08:56:38 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mac_so_long.h"

void	error_newline(char **split);
void	error_map_walls(char **split);
void	error_map_invalid_path(char **split);
void	error_map_bigger_than_screen(char **split);

void	error_map_bigger_than_screen(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mMAP BIGGER THAN SCREEN! \033[0m💔\n", 40);
	exit(1);
}

void	error_map_invalid_path(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mINVALID PATH! \033[0m💔\n", 30);
	exit(1);
}

void	error_map_walls(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mMap Must Be Sourrounded By Walls!\033[0m\n", 45);
	exit(1);
}

void	error_newline(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mMAP HAS EMPTY NEWLINE! \033[0m💔\n", 40);
	exit(1);
}
