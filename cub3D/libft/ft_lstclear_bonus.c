/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:59:49 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 10:02:30 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
// void del(void *str
// {
//     free(str;
// }
// int main()
// {
//     t_list *lst;
//     t_list *new;
//     t_list *new2;
//     t_list *new3;
//     t_list *last;

//     lst = ft_lstnew(strdup("A"));
//     new = ft_lstnew(strdup("B"));
//     new2 = ft_lstnew(strdup("C"));
//     new3 = ft_lstnew(strdup("D"));
//     ft_lstadd_front(&lst,new);
//     ft_lstadd_front(&lst,new2);
//     ft_lstadd_front(&lst,new3);

//     printf("Before lstclear:\n");
//     while(lst)
//     {
//         printf("%s\n",lst->str;
//         lst = lst->next;
//     }

//     ft_lstclear(&new, del);
//     printf("After lstclear:\n");
//      printf("%s\n",new2->str;

//     return (0);
// }