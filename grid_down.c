/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:18:15 by gallard           #+#    #+#             */
/*   Updated: 2015/03/01 15:14:29 by nbrizini         ###   ########.fr       */
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
				if (env->t.t[j + 1][i] == VIDE && env->t.t[j][i] != VIDE)
				{
					env->t.t[j + 1][i] = env->t.t[j][i];
					env->t.t[j + 0][i] = VIDE;
					flg = 1;
					break ;
				}
			}
		}
	}
}

static int		grid_up_merge(t_env *env)
{
	int		ret;
	int		i;
	int		j;

	ret = 0;
	i = -1;
	while (++i < env->cells)
	{
		j = env->cells;
		while (--j >= 1)
		{
			if (env->t.t[j][i] != VIDE && env->t.t[j - 1][i] == env->t.t[j][i])
			{
				env->t.t[j][i] *= 2;
				env->t.t[j - 1][i] = VIDE;
				ret++;
			}
		}
	}
	return (ret);
}

static int		grid_down_todo(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->cells)
	{
		j = env->cells - 1;
		while (env->t.t[j][i] != VIDE && j >= 0)
			j--;
		while (env->t.t[j][i] == VIDE && j >= 0)
			j--;
		if (j != -1)
			return (1);
	}
	return (0);
}

int				grid_down(t_env *env)
{
	if (!grid_down_todo(env))
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
