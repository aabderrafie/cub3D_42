/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:32:11 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 10:03:10 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->str);
		free(lst);
	}
	else
		return ;
}
// void	del(void *str
// {
// 	free(str;
// }

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

//     printf(" before delone : \n");
//     while(lst)
//     {
//         printf("%s\n",lst->str;
//         lst = lst->next;
//     }

//     printf(" after delone : \n");
//     while(lst)
//     {
//         ft_lstdelone(lst,del);
//          printf("%s\n",lst->str;
//     }

//     printf("%s\n",new->str;
//      printf("%s\n",new2->str;
//       printf("%s\n",new3->str;
//     return (0);
// }