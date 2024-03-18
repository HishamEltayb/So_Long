/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_error_characters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:00:12 by heltayb           #+#    #+#             */
/*   Updated: 2024/03/08 08:56:36 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mac_so_long.h"

void	error_more_than_exit(char **split);
void	error_no_collectables(char **split);
void	error_more_than_player(char **split);

void	error_more_than_exit(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mMUST BE ONE EXIT !\033[0m\n", 31);
	exit(1);
}

void	error_more_than_player(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mMUST BE ONE PLAYER !\033[0m\n", 39);
	exit(1);
}

void	error_no_collectables(char **split)
{
	free_split(split);
	write(2, "\033[1;31mError\033[0m\n", 18);
	write(2, "\033[1;31mTHERE IS NO COLLECTABLES!\033[0m\n", 35);
	exit(1);
}
