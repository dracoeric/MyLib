/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:11:47 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 17:37:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	t_list *list;
	t_list *next;

//Test de lstadd
	printf("Creation d'un elem avec content = 'nouveau' et size = 8\n");
	list = ft_lstnew("nouveau", 8);
	ft_putlst(list);
	puts("\nAjout de 'deuxieme'\n");
	ft_lstadd(&list, ft_lstnew("deuxieme", 9));
	ft_putlst(list);
	puts("\net troisieme\n");
	ft_lstadd(&list, ft_lstnew("troisieme", 10));
	ft_putlst(list);
	puts("\n\n");

//Test de del et delone
	puts("list = ");
	ft_putlst(list);
	next = list->next;
	puts("\n\nnext = ");
	ft_putlst(next);
	puts("\nSuppression du premier maillon de list\nImpression de list :");
	ft_lstdelone(&list, &ft_memdellst);
	ft_putlst(list);
	puts("\n next est encore la");
	ft_putlst(next);
	puts("\n list = next et next = list->next\nlist =");
	list = next;
	next = list->next;
	ft_putlst(list);
	puts("\nnext =");
	ft_putlst(next);
	puts("\nutilisation de lstdel\nlist =");
	ft_lstdel(&list, &ft_memdellst);
	ft_putlst(list);
	puts("\nnext =");
	ft_putlst(next);
	puts("\n\n");

//test de lstier
	list = ft_lstnew("nouveau", 8);
	ft_lstadd(&list, ft_lstnew("deuxieme", 9));
	ft_lstadd(&list, ft_lstnew("troisieme", 10));
	puts("recreation de list=");
	ft_putlst(list);
	puts("impression de list via lstiter et printlstone");
	ft_lstiter(list, &ft_printlstone);

//test de lstmap
	next = ft_lstmap(list, &ft_lsttoupper);
	puts("\nnext = lstmap avec f = lsttoupper\nnest = ");
	ft_putlst(next);

	return (0);
}
