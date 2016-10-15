/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmk_disp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrizini <nbrizini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:55:01 by nbrizini          #+#    #+#             */
/*   Updated: 2015/03/01 18:18:36 by nbrizini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demika2.h"

static void		str1(t_env *env, int h)
{
	char const	uwin[] = "U WINNED--";
	char const	lost[] = "U LOSTED--";
	int			o;
	int			i;

	o = 0;
	i = 0;
	while (i < env->width)
	{
		if (env->status != NONE && \
			(i > env->width / 2 - 5 && i < env->width / 2 + 5) \
			&& h == env->height / 2)
		{
			ft_putchar(env->status == LOST ? lost[o++] : uwin[o++]);
		}
		else if (i == 0 || i == env->width / 4 || i == env->width / 2
			|| i == env->width * 3 / 4)
			ft_putchar('+');
		else
			ft_putchar('-');
		i++;
	}
	ft_putchar('+');
}

static void		str2(t_env *env)
{
	int i;

	i = 0;
	while (i < env->width)
	{
		if (i == 0 || i == env->width / 4 || i == env->width / 2
			|| i == env->width * 3 / 4)
			ft_putchar('|');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('|');
}

static void		str3(t_env *env, int j)
{
	int i;
	int k;

	k = 0;
	i = -1;
	while (++i < env->width)
	{
		if (i == 0 || i == env->width / 4 || i == env->width / 2
			|| i == env->width * 3 / 4)
			ft_putchar('|');
		else if (i == (env->width / 4) / 2
				|| i == (env->width * 3 / 4) / 2
				|| i == (env->width * 5 / 4) / 2
				|| i == (env->width * 7 / 4) / 2)
		{
			dmk_color(env->t.t[j][k]);
			env->t.t[j][k] != VIDE ? ft_putnbr(env->t.t[j][k]) : \
			ft_putchar(' ');
			dmk_color(-1);
			k++;
		}
		else
			ft_putchar(' ');
	}
	ft_putchar('|');
}

static void		f_disp(t_env *env)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < env->height)
	{
		if (i == 0 || i == env->height / 4 || i == env->height / 2
			|| i == env->height * 3 / 4)
			str1(env, i);
		else if (i == (env->height / 4) / 2
				|| i == (env->height * 3 / 4) / 2
				|| i == (env->height * 5 / 4) / 2
				|| i == (env->height * 7 / 4) / 2)
		{
			str3(env, k);
			k++;
		}
		else
			str2(env);
		write(1, "\r\n", 2);
		i++;
	}
	str1(env, i);
}

void			dmk_disp(t_env *env)
{
	char const	s_ts[] = "Too smalled!";
	char const	s_sc[] = "Score:\t\t";

	if (env->height < 10 || env->width < 30)
		write(1, s_ts, sizeof(s_ts) - 1);
	else
	{
		f_disp(env);
		write(1, s_sc, sizeof(s_sc) - 1);
		ft_putnbr(env->score);
	}
}
