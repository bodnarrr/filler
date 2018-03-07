/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:48:10 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/05 13:48:11 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

char		*ft_read_map(t_filler *prm)
{
	char	*map;
	int		i;
	char	*line;
	char	*temp;

	if (get_next_line(0, &line) == 0)
		return (NULL);
	RW = ft_atoi(ft_strchr(line, ' ') + 1);
	CL = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	map = ft_strnew(0);
	i = -1;
	while (++i < RW)
	{
		get_next_line(0, &line);
		temp = ft_strsub(line, 4, CL);
		map = ft_str_clean_join(&map, &temp);
		ft_strdel(&line);
	}
	return (map);
}
