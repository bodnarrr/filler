/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:14:31 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/05 13:14:33 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

char		ft_get_player(void)
{
	char	*line;
	char	ret;

	get_next_line(0, &line);
	if (line[10] == '1')
		ret = 'O';
	else
		ret = 'X';
	ft_strdel(&line);
	return (ret);
}
