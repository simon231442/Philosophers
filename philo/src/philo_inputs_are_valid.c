/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_input_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:34:02 by srenaud           #+#    #+#             */
/*   Updated: 2025/04/27 14:43:33 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_input_is_valid(char *av);

/**
 * @brief Vérifie la validité des arguments passés au programme principal.
 *
 * Cette fonction, appelée par main, contrôle :
 *  - Que le nombre d'arguments est correct (5 ou 6)
 *  - Que chaque argument est un entier positif valide, en appelant
 *    philo_input_is_valid.
 *
 * Si un argument est invalide, un message d'erreur est affiché et le programme
 * est interrompu dans main.
 *
 * @param ac Nombre total d'arguments
 * @param av Tableau des arguments
 * @return 1 si tous les arguments sont valides, 0 sinon
 */

int	philo_inputs_are_valid(int ac, char **av)
{
	int	i;
	
	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Usage: ./philo [number of philo] [time to die] [time to eat]");
		printf("[time to sleep] [number of meal per philo]");
		return (0);
	}
	while (i < ac)
	{
		if (!philo_input_is_valid(av[i]))
			return (printf("wrong argument"), 0);
		i++;
	}
	return (1);
}

/**
 * @brief Vérifie la validité d'un argument individuel du programme.
 *
 * Cette fonction s'assure que l'argument :
 *  - Ne contient que des caractères numériques
 *  - Représente une valeur entière comprise entre 1 et INT_MAX
 * 
 * Elle est appelée pour chaque argument par philo_inputs_are_valid.
 * Voir philo_init_data pour la définition précise des arguments attendus.
 *
 * @param av Chaîne représentant l'argument à vérifier
 * @return 1 si l'argument est valide, 0 sinon
 *
 * @note Si un argument est invalide, le programme sera interrompu dans main.
 */

int	philo_input_is_digit(char *av);
int	philo_input_is_in_range(char *av);

int	philo_input_is_valid(char *av)
{
	if (!philo_input_is_digit(av))
		return (0);
	if (!philo_input_is_in_range(av))
		return (0);
	return (1);
}

int	philo_input_is_digit(char *av)
{
	while (*av)
	{
		if (!philo_utils_is_digit(*av))
			return (0);
		av++;
	}
	return (1);
}

int	philo_input_is_in_range(char *av)
{
	long	nb;

	nb = philo_utils_atol(av);
	if (nb > INT_MAX || nb < 1)
		return (0);
	return (1);
}
