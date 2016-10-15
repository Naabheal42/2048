/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:18:15 by gallard           #+#    #+#             */
/*   Updated: 2015/03/01 16:33:14 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demika2.h"

static	void	grid_up_spill(t_env *env)
{
	int		i;
	int		j;
	int		flg;

	i = -1;
	while (++i < env->cells)
	{
		flg = 1;
		while (flg)
		{
			flg = 0;
			j = -1;
			while (++j < env->cells - 1)
			{
				if (env->t.t[i][j + 1] == VIDE && env->t.t[i][j] != VIDE)
				{
					env->t.t[i][j + 1] = env->t.t[i][j];
					env->t.t[i][j + 0] = VIDE;
					flg = 1;
					break ;
				}
			}
		}
	}
}

static int		grid_up_merge(t_env *env)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	i = -1;
	while (++i < env->cells)
	{
		j = env->cells;
		while (--j >= 1)
		{
			if (env->t.t[i][j] != VIDE && env->t.t[i][j - 1] == env->t.t[i][j])
			{
				env->t.t[i][j] *= 2;
				env->t.t[i][j - 1] = VIDE;
				ret++;
			}
		}
	}
	return (ret);
}

static int		grid_right_todo(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->cells)
	{
		j = env->cells - 1;
		while (env->t.t[i][j] != VIDE && j >= 0)
			j--;
		while (env->t.t[i][j] == VIDE && j >= 0)
			j--;
		if (j != -1)
			return (1);
	}
	return (0);
}

int				grid_right(t_env *env)
{
	if (!grid_right_todo(env))
	{
		if (!grid_up_merge(env))
			return (1);
		grid_up_spill(env);
		return (0);
	}
	grid_up_spill(env);
	grid_up_merge(env);
	grid_up_spill(env);
	return (0);
}
