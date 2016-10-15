/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:56:01 by gallard           #+#    #+#             */
/*   Updated: 2015/03/01 17:56:04 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demika2.h"

void		add_num(t_env *env)
{
	int	i;
	int	j;

	i = rand() % env->cells;
	j = rand() % env->cells;
	while (env->t.t[i][j] != VIDE)
	{
		i = rand() % env->cells;
		j = rand() % env->cells;
	}
	env->t.t[i][j] = 2 * ((rand() % 4) / 2) + 2;
}
