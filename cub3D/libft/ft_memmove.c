/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:39:20 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/26 16:35:38 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	if (!dst && !src)
		return (NULL);
	i = 0;
	str = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str2 < str)
	{
		while (len--)
			str[len] = str2[len];
	}
	else
	{
		ft_memcpy(str, str2, len);
	}
	return (dst);
}

// int main()
// {

//   int dst[10] = {1,2,3,4,5,6,7,8,9,10};
//     char src[] = "hello";

//    memcpy(NULL, NULL, 6);
// printf("%s - ", ft_memcpy(NULL, NULL, 6));
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d - ", dst[i]);
//     }
//     return (0);
// }