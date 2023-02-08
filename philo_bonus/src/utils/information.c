/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:35:32 by ddzuba            #+#    #+#             */
/*   Updated: 2023/01/13 17:35:32 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/* Just for printing actual info about philo - philo start time, id, message */
/*sem_post () увеличивает (разблокирует) семафор, на который указывает sem. 
    Если значение семафора становится больше нуля, 
    тогда другой процесс или поток, заблокированный вызовом sem_wait(3),будет 
    разбужен и продолжит блокировку семафора.*/
void	info_print(t_philo *philo, char *str)
{
	sem_wait(philo->print);
	printf("%lld %d %s\n",
		get_timestamp() - philo->start_time, philo->name_of_philo, str);
	sem_post(philo->print);
}

// ◦ timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died
