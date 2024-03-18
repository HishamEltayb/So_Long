/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_error_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:35:59 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 10:29:38 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linux_so_long.h"

void	error_split(char *join);
void	error_short_arguments(void);
void	error_too_much_arguments(void);
void	error_map_not_valid(char **split);
void	error_joining(char *str, char *temp);

void	error_map_not_valid(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 17);
	write(2, "\033[1;31mThe map is NOT valid!\033[0m\n", 34);
	exit(1);
}

void	error_split(char *join)
{
	free(join);
	write(1, "\033[1;31mError Creating splited map!\033[0m\n", 40);
	exit(1);
}

void	error_joining(char *str, char *temp)
{
	free(temp);
	free(str);
	write(2, "\033[1;31mFt_Strjoin Malloc Error!\033[0m\n", 37);
	exit(1);
}

void	error_short_arguments(void)
{
	write(2, "\033[1;31mShort Arguments, \033[0m", 29);
	write(2, "\033[1;31mPlease Enter a Map! Ex: (\033[0m", 37);
	write(2, "\033[1;32m./so_long maps/map1.ber\033[0m", 35);
	write(2, "\033[1;31m)\033[0m\n", 14);
	exit(1);
}

void	error_too_much_arguments(void)
{
	write(2, "\033[1;31mToo Much Arguments! Ex: (\033[0m", 37);
	write(2, "\033[1;32m./so_long maps/map1.ber\033[0m", 35);
	write(2, "\033[1;31m)\033[0m\n", 14);
	exit(1);
}
