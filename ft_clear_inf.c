/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_inf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:30:39 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/06 11:30:40 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_clear_inf(t_filler *prm, char **map, char **token)
{
	ft_strdel(map);
	*map = NULL;
	ft_strdel(token);
	*token = NULL;
	prm->res_x = 0;
	prm->res_y = 0;
	prm->tk_cols = 0;
	prm->tk_rows = 0;
	ft_bzero(&prm->poss, sizeof(int) * 10000);
	prm->nb_poss = 0;
}
