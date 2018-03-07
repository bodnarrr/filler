/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:30:30 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/05 14:30:31 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

char		*ft_get_token(t_filler *prm)
{
	char	*line;
	char	*temp;
	char	*token;
	int		i;

	get_next_line(0, &line);
	prm->tk_rows = ft_atoi(ft_strchr(line, ' ') + 1);
	prm->tk_cols = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	ft_strdel(&line);
	token = ft_strnew(0);
	i = -1;
	while (++i < prm->tk_rows)
	{
		get_next_line(0, &line);
		temp = ft_strdup(line);
		token = ft_str_clean_join(&token, &temp);
		ft_strdel(&line);
	}
	prm->last_pos = CL * (RW - prm->tk_rows + 1) - prm->tk_cols;
	return (token);
}
