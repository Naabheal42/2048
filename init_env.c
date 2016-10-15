/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:55:54 by gallard           #+#    #+#             */
/*   Updated: 2015/03/01 19:19:10 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demika2.h"

static void	init_grid(t_grid *g)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			g->t[i][j] = VIDE;
		}
	}
}

static void	init_game(t_env *env)
{
	init_grid(&env->t);
	add_num(env);
	add_num(env);
}

static int	check_winval(void)
{
	int const	val = WIN_VALUE;
	int			i;

	i = 1;
	while ((i <<= 1))
	{
		if (i == val)
			return (1);
	}
	return (0);
}

int			init_env(t_env *env)
{
	env->status = NONE;
	env->score = 0;
	env->height = LINES - 2;
	env->width = COLS - 1;
	env->cells = 4;
	if (!check_winval())
		return (0);
	init_grid(&env->prevt);
	init_game(env);
	return (1);
}
