/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_hasdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:18:15 by gallard           #+#    #+#             */
/*   Updated: 2015/02/28 16:33:58 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demika2.h"

static int		grid_hd_vert(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->cells)
	{
		j = 0;
		while (++j < env->cells)
		{
			if (env->t.t[j][i] != VIDE && env->t.t[j - 1][i] == env->t.t[j][i])
				return (1);
		}
	}
	return (0);
}

static int		grid_hd_horiz(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->cells)
	{
		j = -1;
		while (++j < env->cells - 1)
		{
			if (env->t.t[i][j] != VIDE && env->t.t[i][j + 1] == env->t.t[i][j])
				return (1);
		}
	}
	return (0);
}

int				grid_hasdouble(t_env *env)
{
	return (grid_hd_horiz(env) || grid_hd_vert(env));
}
