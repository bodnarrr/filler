/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:57:18 by abodnar           #+#    #+#             */
/*   Updated: 2018/02/27 14:57:19 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int				main(void)
{
	t_filler	prm;
	char		*map;
	char		*token;

	ft_bzero(&prm, sizeof(t_filler));
	prm.player = ft_get_player();
	prm.opp = (prm.player == 'O') ? 'X' : 'O';
	while (1)
	{
		map = ft_read_map(&prm);
		if (!map)
			break ;
		token = ft_get_token(&prm);
		prm.nb_poss = ft_find_poss(map, token, &prm);
		if (prm.nb_poss == 0)
			ft_printf("0 0\n");
		ft_best_pos(&prm, map, token);
		ft_printf("%d %d\n", prm.res_y, prm.res_x);
		ft_clear_inf(&prm, &map, &token);
	}
	return (0);
}
