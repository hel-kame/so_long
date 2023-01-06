/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:46:52 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/06 09:06:26 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	success_message(void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("bonus/success_message", O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
		return (-1);
	ft_printf("\n");
	i = 0;
	while (str)
	{
		i++;
		ft_printf("\e[1m\x1B[38;5;%dm%s\033[0m", i, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}

int	fail_message(void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("bonus/fail_message", O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
		return (-1);
	ft_printf("\n");
	i = 0;
	while (str)
	{
		i++;
		ft_printf("\t\e[1m\x1B[38;5;88m%s\033[0m", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}
