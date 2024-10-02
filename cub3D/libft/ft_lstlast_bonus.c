/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:43:38 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 10:02:30 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// int main(void)
// {
//     t_list *lst;
//     t_list *new;
//     t_list *new2;
//     t_list *new3;
//     t_list *last;

//     lst = ft_lstnew("A");
//     new = ft_lstnew("B");
//     new2 = ft_lstnew("C");
//     new3 = ft_lstnew("D");
//     ft_lstadd_front(&lst,new);
//     ft_lstadd_front(&lst,new2);
//     ft_lstadd_front(&lst,new3);

//     last = ft_lstlast(lst);
//     printf("%s \t",last->str;

// }