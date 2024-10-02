/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:22 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:55:29 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && (count * size) / count != size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int	main(void)
// {
//     int *str;

//     str = ft_calloc(10, 4);

//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d \t", str[i]);
//     }

//     return (0);
// }
