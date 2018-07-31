/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filloptiontwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:09:07 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/30 16:26:15 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*convert_day(int nbday)
{
	char	*forfree;
	char	*temp;

	forfree = ft_itoa(nbday);
	if (ft_strlen(forfree) == 1)
	{
		temp = ft_strjoin(" ", forfree);
		free(forfree);
		return (temp);
	}
	return (forfree);
}

char	*convert_mon(int nbmon)
{
	if (nbmon == 0)
		return (ft_strdup("Jan"));
	if (nbmon == 1)
		return (ft_strdup("Feb"));
	if (nbmon == 2)
		return (ft_strdup("Mar"));
	if (nbmon == 3)
		return (ft_strdup("Apr"));
	if (nbmon == 4)
		return (ft_strdup("May"));
	if (nbmon == 5)
		return (ft_strdup("Jun"));
	if (nbmon == 6)
		return (ft_strdup("Jul"));
	if (nbmon == 7)
		return (ft_strdup("Aug"));
	if (nbmon == 8)
		return (ft_strdup("Sep"));
	if (nbmon == 9)
		return (ft_strdup("Oct"));
	if (nbmon == 10)
		return (ft_strdup("Nov"));
	if (nbmon == 11)
		return (ft_strdup("Dec"));
	return (NULL);
}

char	*convert_hour_next(char *temp_hour, char *temp_min, char *forfree)
{
	forfree = temp_hour;
	temp_hour = ft_strjoin(forfree, ":");
	free(forfree);
	forfree = temp_hour;
	temp_hour = ft_strjoin(forfree, temp_min);
	free(forfree);
	free(temp_min);
	return (temp_hour);
}

char	*convert_hour(int hour, int min)
{
	char	*temp_hour;
	char	*temp_min;
	char	*forfree;

	if (hour < 10)
	{
		forfree = ft_itoa(hour);
		temp_hour = ft_strjoin("0", forfree);
		free(forfree);
	}
	else
		temp_hour = ft_itoa(hour);
	if (min < 10)
	{
		forfree = ft_itoa(min);
		temp_min = ft_strjoin("0", forfree);
		free(forfree);
	}
	else
		temp_min = ft_itoa(min);
	temp_hour = convert_hour_next(temp_hour, temp_min, forfree);
	return (temp_hour);
}
