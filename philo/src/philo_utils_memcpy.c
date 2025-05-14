/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_memcpy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:17:47 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 09:17:47 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_utils_memcpy(void *dest, void *src, int size)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
}
