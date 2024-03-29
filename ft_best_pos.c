/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:36:17 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/06 11:36:18 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void	ft_choose_best(t_filler *prm, int *imap, char *token, int summ)
{
	int		i;
	int		j;
	int		best;
	int		curr_summ;

	i = -1;
	best = 0;
	j = 0;
	while (++i < prm->nb_poss)
	{
		j = -1;
		curr_summ = 0;
		while (++j < prm->tk_cols * prm->tk_rows)
		{
			if (j < prm->tk_cols && token[j] == '*')
				curr_summ += imap[(prm->poss)[i] + j];
			if (j >= prm->tk_cols && token[j] == '*')
				curr_summ += imap[CH_MAP_POS];
		}
		if (curr_summ < summ && (summ = curr_summ) == curr_summ)
			best = i;
	}
	prm->res_y = (prm->poss)[best] / CL;
	prm->res_x = (prm->poss)[best] % CL;
}

static int	ft_check_pos(int i, int **imap, t_filler *prm, int find)
{
	if ((*imap)[i] == 0 && (((i - CL - 1) % CL != CL - 1 && i - CL - 1
			>= 0 && (*imap)[i - CL - 1] == find) || (i - CL >= 0 &&
			(*imap)[i - CL] == find) || ((i - CL + 1) % CL != 0 && i - CL + 1
			>= 0 && (*imap)[i - CL + 1] == find) || ((i - 1) % CL != CL - 1 &&
			i - 1 >= 0 && (*imap)[i - 1] == find) || ((i + 1) % CL != 0 && i + 1
			< RW * CL && (*imap)[i + 1] == find) || ((i + CL - 1) % CL != CL - 1
			&& i + CL - 1 < RW * CL && (*imap)[i + CL - 1] == find) || (i + CL <
			RW * CL && (*imap)[i + CL] == find) || ((i + CL + 1) % CL != 0 && i
			+ CL + 1 < RW * CL && (*imap)[i + CL + 1] == find)))
		return (1);
	return (0);
}

static void	ft_int_map_maker(int **imap, t_filler *prm, int *empty, int size)
{
	int		i;
	int		find;
	int		count;

	find = 0;
	count = 0;
	while ((*empty) > 0 && ++find > 0)
	{
		i = -1;
		count = 0;
		while (++i < size)
		{
			if (ft_check_pos(i, imap, prm, find))
			{
				(*imap)[i] = find + 1;
				(*empty)--;
				count++;
			}
		}
		if (count == 0)
			break ;
	}
}

static void	ft_int_map_prepare(int **imap, char *map, t_filler *prm, int *empty)
{
	int		i;

	i = -1;
	while (++i < CL * RW)
	{
		if (map[i] == prm->player || map[i] == prm->player + 32)
		{
			(*imap)[i] = -1;
			(*empty)--;
		}
		if (map[i] == prm->opp || map[i] == prm->opp + 32)
		{
			(*imap)[i] = 1;
			(*empty)--;
		}
	}
}

void		ft_best_pos(t_filler *prm, char *map, char *token)
{
	int		*int_map;
	int		size;
	int		empty;

	size = RW * CL;
	empty = RW * CL;
	int_map = (int*)malloc(sizeof(int) * size);
	ft_bzero(int_map, sizeof(int) * size);
	ft_int_map_prepare(&int_map, map, prm, &empty);
	ft_int_map_maker(&int_map, prm, &empty, CL * RW);
	ft_choose_best(prm, int_map, token, INT_MAX);
}
