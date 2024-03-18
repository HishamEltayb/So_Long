/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_error_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:30:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 09:00:20 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_so_long.h"

void	error_map_read(char *str);
void	error_map_not_found(void);
void	error_map_empty(char *str);
void	error_map_wrong_name(void);
void	error_map_not_rectangular(char **split);

void	error_map_read(char *str)
{
	free(str);
	write(2, "\033[1;31mCouldn't Read The file!\033[0m\n", 31);
	exit(1);
}

void	error_map_not_found(void)
{
	write(2, "\033[1;31mMap Not Found! \033[0m", 27);
	write(2, "\033[1;31mPlease Enter Valid Map! Ex: (\033[0m", 40);
	write(2, "\033[1;32m./so_long maps/map1.ber\033[0m", 35);
	write(2, "\033[1;31m)\033[0m\n", 14);
	exit(1);
}

void	error_map_empty(char *str)
{
	free(str);
	write(2, "\033[1;31mThe file is Empty!\033[0m\n", 31);
	exit(1);
}

void	error_map_wrong_name(void)
{
	write(2, "\033[1;31mWrong Map Name! \033[0m", 28);
	write(2, "\033[1;31mPlease Enter Valid Map! Ex: (\033[0m", 40);
	write(2, "\033[1;32m./so_long maps/map1.ber\033[0m", 35);
	write(2, "\033[1;31m)\033[0m\n", 14);
	exit(1);
}

void	error_map_not_rectangular(char **split)
{
	free_split(split);
	write(2, "\033[1;31mThe map is NOT Rectangular!\033[0m\n", 40);
	exit(1);
}
