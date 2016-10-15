/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmk_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:22:52 by gallard           #+#    #+#             */
/*   Updated: 2015/02/28 19:23:02 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demika2.h"

static int	is_won(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->cells)
	{
		j = -1;
		while (++j < env->cells)
		{
			if (env->t.t[i][j] == WIN_VALUE)
				return (1);
		}
	}
	return (0);
}

static int	is_lost(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->cells)
	{
		j = -1;
		while (++j < env->cells)
		{
			if (env->t.t[i][j] == VIDE)
				return (0);
		}
	}
	return (1);
}

static void	loop_khbit(t_env *env, int key, int *nope)
{
	if (key == KEY_UP)
		*nope = grid_up(env);
	else if (key == KEY_DOWN)
		*nope = grid_down(env);
	else if (key == KEY_LEFT)
		*nope = grid_left(env);
	else if (key == KEY_RIGHT)
		*nope = grid_right(env);
	else if (key == 'n')
		*nope = init_env(env);
	else if (key == 'b')
	{
		env->status = NONE;
		env->t = env->prevt;
		*nope = !!1;
	}
	else
		*nope = 1;
}

int			loop(t_env *env)
{
	int		key;
	int		nope;
	t_grid	tmp;

	key = 0;
	while (key != 0x1B)
	{
		clear();
		erase();
		refresh();
		dmk_disp(env);
		refresh();
		nope = 0;
		key &= 0;
		key = getch();
		tmp = env->t;
		loop_khbit(env, key, &nope);
		env->status = (is_won(env)) ? WON : env->status;
		(!nope) ? add_num(env) : (void)1337;
		if (is_lost(env) && !grid_hasdouble(env))
			env->status = LOST;
		(!nope) ? (env->prevt = tmp) : (void)42;
		env->score += ((!nope) ? (rand() % 4) : 0);
	}
	return (0);
}
