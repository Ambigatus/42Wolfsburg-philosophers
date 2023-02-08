/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:24:32 by ddzuba            #+#    #+#             */
/*   Updated: 2023/02/08 17:49:11 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* Eat function */
void	meal(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->fork[philo->left_hand]);
	print_output(philo, "has taken a fork 🍽");
	pthread_mutex_lock(&table->fork[philo->right_hand]);
	print_output(philo, "has taken a fork 🍽");
	print_output(philo, "is eating 🍕");
	sleep_for_given_time(table->time_to_eat);
	philo->lst_meal = c_time();
	philo->meal_times++;
	pthread_mutex_unlock(&table->fork[philo->right_hand]);
	pthread_mutex_unlock(&table->fork[philo->left_hand]);
}
