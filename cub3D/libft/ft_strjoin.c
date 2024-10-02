/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:02:35 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/26 16:45:55 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;

// 	s1 = "My name is Abderrafie";
// 	s2 = " and I am a student at 42 ";
// 	s3 = ft_strjoin(s1, s2);
// 	printf("%lu \n", strlen(s3));
// 	printf("%s \n", ft_strjoin(s1, s2));
// 	return (0);
// }
