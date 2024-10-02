/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:02:55 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/24 16:49:23 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str; 

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int main()
// {
//  int str2[50] = {1,2,3,4,9,9,627,8,2,3};

// 	for(int i = 0; i < 10; i++){
// 			printf("%d \t", str2[i]);
// 	}
// 	printf("\n");
//    ft_memset(str2, 'a', 8);

//    for(int i = 0; i < 10; i++){
//     printf("%d \t", str2[i]);
// }

//     return (0);
// }
