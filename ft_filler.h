/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:57:48 by abodnar           #+#    #+#             */
/*   Updated: 2018/02/27 14:57:49 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# define CL prm->cols
# define RW prm->rows
# define MAP_POS i + (j / prm->tk_cols * CL) + j % prm->tk_cols
# define CH_MAP_POS (prm->poss)[i] + (j / prm->tk_cols * CL) + j % prm->tk_cols

# include "./libftprintf/libftprintf.h"
# include <limits.h>

typedef struct	s_filler
{
	char		player;
	char		opp;
	int			rows;
	int			cols;
	int			res_x;
	int			res_y;
	int			tk_rows;
	int			tk_cols;
	int			last_pos;
	int			poss[10000];
	int			nb_poss;
}				t_filler;

typedef struct	s_token
{
	int			rows;
	int			cols;
}				t_token;

char			ft_get_player(void);
char			*ft_read_map(t_filler *prm);
char			*ft_str_clean_join(char **str1, char **str2);
char			*ft_get_token(t_filler *prm);
int				ft_find_poss(char *map, char *token, t_filler *prm);
void			ft_clear_inf(t_filler *prm, char **map, char **token);
void			ft_best_pos(t_filler *prm, char *map, char *token);

#endif
