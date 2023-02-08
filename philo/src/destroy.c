/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:14:05 by ddzuba            #+#    #+#             */
/*   Updated: 2023/02/08 17:39:23 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Join all philo threads on exit */
void	exit_function(size_t n, t_table *table)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		pthread_join(table->philo[n].tread, NULL);
		i++;
	}
}

/* Detach and destroys all mutex */
void	destroy(size_t n, t_table *table)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		pthread_detach(table->philo[n].tread);
		pthread_mutex_destroy(&table->fork[n]);
		i++;
	}
	pthread_mutex_destroy(&table->write);
}

/* Clear exit with all previous functions */
void	ending_check(t_table *table)
{
	exit_function(table->num_of_philo, table);
	destroy(table->num_of_philo, table);
	free(table);
}
