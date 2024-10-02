/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:16:13 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/26 16:43:05 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (dstsize <= i)
		return (j + dstsize);
	while (src[k] && i + k < dstsize - 1)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + j);
}

// int main (){
//     char src[] = "Hello Abderrafie!";
//     char dst[] = " hi  askal ";
//     printf("%zu \n", ft_strlcat(dst, src, 25));
//     printf("%s \n", dst);
//     return (0);
// }