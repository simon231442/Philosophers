/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_ritoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:06:42 by srenaud           #+#    #+#             */
/*   Updated: 2025/05/14 22:06:42 by srenaud          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Convertit un entier en chaîne via récursion.
 *
 * Écrit la représentation décimale de n dans le buffer dest.
 * L'appel récursif permet de placer les chiffres dans l'ordre naturel.
 * La position de dest est incrémentée à chaque écriture.
 *
 * @param n     Valeur entière à convertir.
 * @param dest  Buffer cible pour la chaîne (sans terminaison '\0').
 * @return      Pointeur vers la position après le dernier caractère.
 */

char	*philo_utils_ritoa(time_t n, char *dest)
{
	if (n >= 10)
		dest = philo_utils_ritoa(n / 10, dest);
	*dest = (n % 10) + '0';
	return (dest + 1);
}
