/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filloptiontwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:09:07 by alsomvil          #+#    #+#             */
/*   Updated: 2018/08/11 15:27:00 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*date_modif(char *tmp)
{
	char	*days;
	int		i;
	int		j;

	i = 4;
	j = 0;
	days = malloc(sizeof(char) * 7);
	while (i < 10)
	{
		days[j++] = tmp[i++];
	}
	days[j] = '\0';
	return (days);
}

char	*date_modif_two(char *date)
{
	char	*years;
	char	*temp;
	int		i;
	int		j;

	i = 20;
	j = 0;
	years = malloc(sizeof(char) * 5);
	while (i < 24)
	{
		years[j++] = date[i++];
	}
	years[j] = '\0';
	temp = ft_strjoin("  ", years);
	free(years);
	return (temp);
}

char	*date_modif_three(char *date)
{
	char	*hours;
	char	*temp;
	int		i;
	int		j;

	i = 11;
	j = 0;
	hours = malloc(sizeof(char) * 6);
	while (i < 16)
	{
		hours[j++] = date[i++];
	}
	hours[j] = '\0';
	temp = ft_strjoin(" ", hours);
	free(hours);
	return (temp);
}

char	*convert_mon(time_t fff, char *date)
{
	char	*hours;
	time_t	timetoday;
	char	*temp;
	char	*days;
	char	*years;

	time(&timetoday);
	days = date_modif(date);
	hours = date_modif_three(date);
	years = date_modif_two(date);
	if (timetoday - fff > 15778800)
	{
		temp = ft_strjoin(days, years);
		free(days);
		free(hours);
		free(years);
		return (temp);
	}
	temp = ft_strjoin(days, hours);
	free(days);
	free(hours);
	free(years);
	return (temp);
}

char	*block_two(char *test, int min)
{
	char	*temp;
	char	*forfree;

	forfree = ft_itoa(min);
	if (ft_strlen(forfree) == 3)
		temp = ft_strjoin(test, ", ");
	else if (ft_strlen(forfree) == 2)
		temp = ft_strjoin(test, ",  ");
	else if (ft_strlen(forfree) == 1)
		temp = ft_strjoin(test, ",   ");
	free(forfree);
	return (temp);
}
