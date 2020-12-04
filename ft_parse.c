/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:18:59 by sbrenton          #+#    #+#             */
/*   Updated: 2020/12/04 17:22:09 by lesia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

t_keys ft_init(t_keys keys)
{
	keys.flags = '\0';
	keys.width = '\0';
	keys.precision = -1;
	keys.length = '\0';
	keys.specifier = '\0';
	return keys;
}

