/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_memset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:27:57 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 09:27:57 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_utils_memset(void *dest, char c, int size)
{
	unsigned char	*d;

	d = (unsigned char *)dest;
	while (size)
	{
		*d = c;
		d++;
		size--;
	}
}
