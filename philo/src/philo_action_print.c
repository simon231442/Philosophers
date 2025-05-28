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
 * Chaque buffer d'action (t_print) est un tableau de BUFF_SIZE octets :
 *   - time_stamp pointe en début de tableau pour y écrire le timestamp
 *     (ms depuis data->time_start),
 *   - id pointe PRECISION_TIME octets plus loin pour y écrire l'ID du philo,
 *   - action pointe PRECISION_TIME + PRECISION_ID octets plus loin pour l'act.
 *
 * Cette fonction :
 *   1. Convertit le timestamp et l'ID en chaîne dans le buffer approprié.
 *   2. Écrit les BUFF_SIZE octets sur stdout.
 *   3. Replace des espaces sur la zone PRECISION_TIME + PRECISION_ID
 *      pour réinitialiser le buffer avant la prochaine utilisation.
 *
 * L'affichage est protégé par le mutex data->mutex[E_PRINT].
 * 
 * il y a une seconde definition de la fonction qui se compile avec make color
 * l'affichage est colore en fonction de l'id et il y a un decalage en debut
 * d'affichage pour plus de lisibilite
 * 
 * Il
 *
 * @param philo        Pointeur vers le philosophe courant.
 * @param buffer_name  Indice du buffer/action
 *                     (E_TAKING, E_EATING, E_SLEEPING, E_THINKING ou E_DYING).
 */

#ifdef COLOR

void	set_color(int id)
{
	static char	*color[6] = {
		"\033[31m", // Rouge
		"\033[32m", // Vert
		"\033[33m", // Jaune
		"\033[34m", // Bleu
		"\033[35m", // Magenta
		"\033[36m"// Cyan
	};

	write(1, color[id % 6], 5);
}

void	philo_action_print(t_philo *philo, int buffer_name)
{
	static int	print_is_off;
	static char	shift_buff[40] = "                                        ";
	static int	up_or_down = 1;
	static int	shift = 1;

	pthread_mutex_lock(&philo->data->mutex[E_PRINT]);
	if (print_is_off)
		return ((void)pthread_mutex_unlock(&philo->data->mutex[E_PRINT]));
	if (buffer_name == E_DYING)
		print_is_off = 1;
	if (shift > philo->data->philo_nb || shift >= 40 || shift <= 0)
		up_or_down *= -1;
	set_color(philo->id);
	write(1, shift_buff, shift);
	shift += up_or_down;
	philo_utils_ritoa(philo_utils_get_time() - philo->data->time_start,
		philo->data->action_print[buffer_name].time_stamp);
	philo_utils_ritoa(philo->id, philo->data->action_print[buffer_name].id);
	write(1, philo->data->action_print[buffer_name].time_stamp, BUFF_SIZE);
	write(1, "\033[0m", 4);
	philo_utils_memset(philo->data->action_print[buffer_name].time_stamp,
		' ', PRECISION_TIME + PRECISION_ID);
	pthread_mutex_unlock(&philo->data->mutex[E_PRINT]);
}

#else

void	philo_action_print(t_philo *philo, int buffer_name)
{
	static int	print_is_off;

	pthread_mutex_lock(&philo->data->mutex[E_PRINT]);
	if (print_is_off)
	{
		pthread_mutex_unlock(&philo->data->mutex[E_PRINT]);
		return ;
	}
	if (buffer_name == E_DYING)
		print_is_off = 1;
	philo_utils_ritoa(philo_utils_get_time() - philo->data->time_start,
		philo->data->action_print[buffer_name].time_stamp);
	philo_utils_ritoa(philo->id, philo->data->action_print[buffer_name].id);
	write(1, philo->data->action_print[buffer_name].time_stamp, BUFF_SIZE);
	philo_utils_memset(philo->data->action_print[buffer_name].time_stamp,
		' ', PRECISION_TIME + PRECISION_ID);
	pthread_mutex_unlock(&philo->data->mutex[E_PRINT]);
}

#endif
