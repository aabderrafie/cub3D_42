/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:42:59 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 10:03:52 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *str)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}
// int main(void)
// {
//     t_list *new;
// 	char *str;
//     str = "Hello Abderrafie Welcome to 42!";
//     new = ft_lstnew(str);
//     printf("%s\n", new->str;
// 	printf("%lu\n", sizeof(t_list));

//     return (0);
// }