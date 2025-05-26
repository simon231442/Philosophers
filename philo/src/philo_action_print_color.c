/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:34:36 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/XX XX:XX:XX by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Affiche l'action d'un philosophe de façon thread-safe.
 *
 * Chaque buffer d'action (t_print) est un tableau de BUFF_SIZE octets structuré ainsi :
 *   - time_stamp pointe en début de tableau pour y écrire le timestamp
 *     (ms depuis data->time_start),
 *   - id pointe PRECISION_TIME octets plus loin pour y écrire l'ID du philosophe,
 *   - action pointe PRECISION_TIME + PRECISION_ID octets plus loin pour le message.
 *
 * Cette fonction :
 *   1. Convertit le timestamp et l'ID en chaîne dans le buffer approprié.
 *   2. Écrit les BUFF_SIZE octets sur stdout.
 *   3. Replace des espaces sur la zone time_stamp (PRECISION_TIME + PRECISION_ID)
 *      pour réinitialiser le buffer avant la prochaine utilisation.
 *
 * L'affichage est protégé par le mutex data->mutex[E_PRINT].
 *
 * @param philo        Pointeur vers le philosophe courant.
 * @param buffer_name  Indice du buffer/action
 *                     (E_TAKING, E_EATING, E_SLEEPING, E_THINKING ou E_DYING).
 */
void	philo_action_print_color(t_philo *philo, int buffer_name)
{
	static char	shift_buff[40] = "                                        ";
	static int	up_or_down = 1;
	static int	shift = 0;

	pthread_mutex_lock(&philo->data->mutex[E_PRINT]);
	if (shift > philo->data->philo_nb || shift >= 40 || shift <= 0)
		up_or_down *= -1;
	write(1, shift_buff, shift);
	shift += up_or_down;
	philo_utils_ritoa(philo_utils_get_time() - philo->data->time_start,
		philo->data->action_print[buffer_name].time_stamp);
	philo_utils_ritoa(philo->id, philo->data->action_print[buffer_name].id);
	write(1, philo->data->action_print[buffer_name].time_stamp, BUFF_SIZE);
	philo_utils_memset(philo->data->action_print[buffer_name].time_stamp,
		' ', PRECISION_TIME + PRECISION_ID);
	pthread_mutex_unlock(&philo->data->mutex[E_PRINT]);
}
