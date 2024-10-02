/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:15:16 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/26 16:15:56 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			j = i;
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	if (j != 0 || str[j] == (char)c)
		return ((char *)str + j);
	return (NULL);
}
/*
int	main(void) {
	char str[] = "mhhgchljello";
	printf("%s \n", ft_strrchr(str, 'm'));
	printf("%s \n", strrchr(str, '\0'));
	return (0);
}
*/