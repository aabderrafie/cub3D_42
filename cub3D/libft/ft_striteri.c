/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:25:52 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/21 15:39:51 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void f2t_toupper(unsigned int i, char *c)
// {
//     int j;
//     for(j = 0; j < i; j++){
//         if(c[j] >= 'a' && c[j] <= 'z')
//             c[j] = c[j] - 32;
//     }
// }

// int main()
// {
//     char str[] = "Hello Abderrafie!";
//     ft_striteri(str, f2t_toupper);

//     printf("%s \n", str);
//     return (0);
// }