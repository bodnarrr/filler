/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_poss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:44:03 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/05 14:44:04 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int	ft_check_token(int i, t_filler *prm, char *map, char *token)
{
	int		j;
	int		touch;

	j = -1;
	touch = 0;
	while (++j < prm->tk_cols * prm->tk_rows)
	{
		if (j < prm->tk_cols && token[j] == '*')
		{
			if (map[i + j] == prm->opp || map[i + j] == prm->opp + 32)
				return (0);
			if (map[i + j] == prm->player || map[i + j] == prm->player + 32)
				touch++;
		}
		if (j >= prm->tk_cols && token[j] == '*')
		{
			if (map[MAP_POS] == prm->opp || map[MAP_POS] == prm->opp + 32)
				return (0);
			if (map[MAP_POS] == prm->player || map[MAP_POS] == prm->player + 32)
				touch++;
		}
	}
	return (touch == 1) ? 1 : 0;
}

int			ft_find_poss(char *map, char *token, t_filler *prm)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (i < CL * RW)
	{
		if (i % CL <= CL - prm->tk_cols && i <= prm->last_pos)
			if (ft_check_token(i, prm, map, token))
			{
				prm->poss[j++] = i;
				res++;
			}
		i++;
	}
	return (res);
}
