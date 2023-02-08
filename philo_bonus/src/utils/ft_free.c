/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:36:40 by ddzuba            #+#    #+#             */
/*   Updated: 2023/01/30 19:20:02 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/* Just free all the memory data */
//sem_unlink - turn off the semaphore
void	ft_free(t_philo *all)
{
	sem_unlink("print");
	sem_unlink("fork");
	sem_close(all->print);
	sem_close(all->fork);
	free(all->pid);
	free(all);
}
