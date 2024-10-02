/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:49:57 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/26 16:27:22 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// int main (){
//     char src[] = "Hello Abderrafie!";
//     char dst[] = "hello world";

//     printf("%s \n", dst);
// 		printf("hadi dyali :%zu \n", ft_strlcpy(dst, src, 1));
//    printf(" hadi dyalhom : %zu \n", strlcpy(dst, src, 1));

//     printf("%s \n", dst);
//
//     return (0);
// }
