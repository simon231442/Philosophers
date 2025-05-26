/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_core_init_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:36:53 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 17:36:53 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initialise les buffers d'affichage des actions.
 *
 * Cette fonction prépare un buffer de taille BUFF_SIZE pour chaque
 * action (TAKING, EATING, SLEEPING, THINKING, DYING). Chaque buffer
 * est rempli d'espaces, et les pointeurs sont configurés :
 *   - time_stamp pointe au début du buffer
 *   - id pointe juste après PRECISION_TIME octets
 *   - action pointe juste après PRECISION_TIME + PRECISION_ID octets
 * Le texte associé à l'action est copié dans le buffer et la dernière
 * position est remplacée par un '\n'.
 *
 * @param buffer Tableau de t_print contenant les buffers d'affichage
 */
void	philo_core_init_print(t_print *buffer)
{
	int			i;
	static char	*action_type[] = {TAKING, EATING, SLEEPING, THINKING, DYING};

	i = 0;
	while (i <= E_DYING)
	{
		philo_utils_memset(buffer[i].time_stamp, 32, BUFF_SIZE);
		buffer[i].id = buffer[i].time_stamp + PRECISION_TIME;
		buffer[i].action = buffer[i].id + PRECISION_ID;
		philo_utils_memcpy(buffer[i].action, action_type[i],
			philo_utils_strlen(action_type[i]));
		buffer[i].time_stamp[BUFF_SIZE - 1] = '\n';
		i++;
	}
}
