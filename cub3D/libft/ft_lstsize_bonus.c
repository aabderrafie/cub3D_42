/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:35:24 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/24 12:57:18 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
// int main()
// {
//        t_list *lst;
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
//     printf("size is : %d  ",ft_lstsize(lst));

//     return (0);
// }