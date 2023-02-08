/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:01 by ddzuba            #+#    #+#             */
/*   Updated: 2023/02/08 18:43:12 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/* Taking time from system. t.tv_sec - in seconds, t.tv_usec - microseconds */
long long	get_timestamp(void)
{
	struct timeval	t;
	long long		now;

	gettimeofday(&t, NULL);
	now = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	return (now);
}

/* Sleep function for philo actions, like "sleep", "eat" etc */
void	ft_usleep(long long time)
{
	long long	start;

	start = get_timestamp();
	while (get_timestamp() - start < time)
		usleep(100);
}
