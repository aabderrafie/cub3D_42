/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:23:52 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/23 14:39:59 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// int	main(void) {
//     char str[] = "Hello World!";
//     char str2[] = "Hello World!";
//     bzero(str, 5);
//     ft_bzero(str2, 5);
//     printf("%s \n", str + 5);
//     printf("%s \n", str2+ 5);
//     return (0);}
