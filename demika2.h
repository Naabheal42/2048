/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demika2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:50:03 by gallard           #+#    #+#             */
/*   Updated: 2015/03/01 18:04:17 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMIKA2_H
# define DEMIKA2_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <ncurses.h>

enum			e_const
{
	WIN_VALUE = 2048
};

# define VIDE	-1

typedef struct
{
	int			t[40][40];
}				t_grid;

typedef enum	e_status
{
	NONE,
	LOST,
	WON
}				t_status;

typedef struct	s_env
{
	int			width;
	int			height;
	int			cells;
	int			score;
	t_grid		t;
	t_grid		prevt;
	t_status	status;
	WINDOW		*w;
}				t_env;

const char		*ft_getenvterm(char **env);
void			dmk_disp(t_env *env);
int				grid_up(t_env *env);
int				grid_down(t_env *env);
int				grid_left(t_env *env);
int				grid_right(t_env *env);
int				grid_hasdouble(t_env *env);
void			add_num(t_env *env);
int				loop(t_env *env);
int				init_env(t_env *env);
void			ft_putchar(char c);
void			ft_putnbr(int n);
char			*ft_strcpy(char *dest, const char *src);
void			dmk_color(int n);
int				init_env(t_env *env);

#endif
