/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:29:00 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 10:02:30 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_last_one(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_last_one(*lst)->next = new;
}
// int main(void)
// {
//     t_list *lst;
//     t_list *new;
//     t_list *new2;
//     t_list *new3;
//     lst = ft_lstnew("A");
//     new = ft_lstnew("B");
//     new2 = ft_lstnew("C");
//     new3 = ft_lstnew("D");
//     ft_lstadd_back(&lst,new);
//     ft_lstadd_back(&lst,new2);
//     ft_lstadd_back(&lst,new3);
//     while(lst != NULL)
//     {
//         printf("%s \t",lst->str;
//         lst = lst->next;
//     }

// }
