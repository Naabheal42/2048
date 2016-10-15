/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmk_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:30:23 by gallard           #+#    #+#             */
/*   Updated: 2015/02/28 19:30:36 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "demika2.h"

void	dmk_color(int n)
{
	int			i;
	char const	col_end[] = "\x1B[0m";
	char		col[6];
	char const	hi[] = "\x1B[1m";

	if (n == -1)
		write(1, col_end, sizeof(col_end) - 1);
	else
	{
		ft_strcpy(col, "\x1B[30m");
		i = 5;
		while (n > 1)
		{
			n /= 2;
			i++;
		}
		if (i >= 7)
			write(1, hi, sizeof(hi) - 1);
		col[sizeof(col) - 3] = '0' + (char)(i % 7);
		write(1, col, sizeof(col) - 1);
	}
}
