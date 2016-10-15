/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:18:15 by gallard           #+#    #+#             */
/*   Updated: 2015/03/01 14:46:31 by nbrizini         ###   ########.fr       */
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
			j = 0;
			while (++j < env->cells)
			{
				if (env->t.t[j - 1][i] == VIDE && env->t.t[j][i] != VIDE)
				{
					env->t.t[j - 1][i] = env->t.t[j][i];
					env->t.t[j - 0][i] = VIDE;
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
		j = 0;
		while (++j < env->cells)
		{
			if (env->t.t[j][i] != VIDE && env->t.t[j - 1][i] == env->t.t[j][i])
			{
				env->t.t[j - 1][i] *= 2;
				env->t.t[j][i] = VIDE;
				ret++;
			}
		}
	}
	return (ret);
}

static int		grid_up_todo(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->cells)
	{
		j = 0;
		while (env->t.t[j][i] != VIDE && j < env->cells)
			j++;
		while (env->t.t[j][i] == VIDE && j < env->cells)
			j++;
		if (j != env->cells)
			return (1);
	}
	return (0);
}

int				grid_up(t_env *env)
{
	if (!grid_up_todo(env))
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
