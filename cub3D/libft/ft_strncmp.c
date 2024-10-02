/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:55:54 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/24 12:55:02 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t i;

// 	i = 1;
// 	if (n == 0)
// 		return (0);
// 	while(s1[i] && s2[i] == s1[i] && i < n)
// 	{
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }

// int	main(void) {
//     char str[] = "test";//
//     char str2[] = "test";//
//     printf("%d \n", ft_strncmp(str, str2, 7));
//     printf("%d \n", strncmp(str, str2, 7));
//     return (0);
// }
