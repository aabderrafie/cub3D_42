/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:24:15 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/26 16:14:27 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char str[] = "teste";
// 	printf("%s \n", ft_strchr(str, 372));
// 	printf("%s \n", ft_strchr(str, 'e'));
// 	printf("%s \n", ft_strchr(str, '\0'));
// 	return (0);
// }