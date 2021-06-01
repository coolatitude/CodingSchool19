/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvanderl <pvanderl@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:22:44 by pvanderl          #+#    #+#             */
/*   Updated: 2021/05/31 21:22:46 by pvanderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void	main_4(t_list *push_test)
{
	printf("before:\n");
	printf_list(push_test);
	ft_list_sort(&push_test, &strcmp);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("sort NULL:\n");
	ft_list_sort(NULL, &strcmp);
	ft_list_sort(&push_test, &strcmp);
	printf("-done\n");
}

static void	main_3(t_list *push_test)
{
	printf("nothing removed:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "toto", &strcmp, &free);
	ft_list_remove_if(&push_test, "tortor", &strcmp, &free);
	ft_list_remove_if(&push_test, "barbar", &strcmp, &free);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	ft_list_remove_if(&push_test, NULL, &strcmp, &free);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("-done\n");
	printf("\n--ft_list_sort\n");
	ft_list_push_front(&push_test, strdup("zwxy"));
	ft_list_push_front(&push_test, strdup("toto"));
	ft_list_push_front(&push_test, strdup("0123456"));
	ft_list_push_front(&push_test, strdup("barbar"));
	ft_list_push_front(&push_test, strdup("rooooom"));
	ft_list_push_front(&push_test, strdup("lol"));
	ft_list_push_front(&push_test, strdup("tortor"));
	ft_list_push_front(&push_test, strdup("mdr"));
	ft_list_push_front(&push_test, strdup("0547"));
	ft_list_push_front(&push_test, strdup("000"));
	ft_list_push_front(&push_test, strdup("zzz"));
	main_4(push_test);
}

static void	main_2(t_list *push_test)
{
	free(push_test);
	push_test = NULL;
	ft_list_push_front(&push_test, strdup("barbar"));
	printf("added: `%s` (s%p : n%p)\n", (char *)(push_test->data),
		   push_test, push_test->next);
	ft_list_push_front(&push_test, NULL);
	printf("added: `%s` (s%p : n%p)\n", (char *)(push_test->data),
		   push_test, push_test->next);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, strdup("toto_r"));
	printf("added: `%s` (s%p : n%p)\n", (char *)(push_test->data),
		   push_test, push_test->next);
	ft_lstclear(&push_test);
	printf("-done\n");
	printf("\n--ft_list_remove_if\n");
	ft_list_push_front(&push_test, strdup("toto"));
	ft_list_push_front(&push_test, strdup("barbar"));
	ft_list_push_front(&push_test, strdup("tortor"));
	ft_list_push_front(&push_test, NULL);
	printf("before:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	main_3(push_test);
}

static void	main_1(
		t_list list, t_list list_next, t_list list_last, t_list *push_test)
{
	printf("\n--ft_list_size\n");
	printf("list content:\n");
	printf_list(&list);
	printf("%d (from first %d)\n", ft_list_size(&list), 3);
	printf("%d (from second %d)\n", ft_list_size(&list_next), 2);
	printf("%d (NULL %d)\n", ft_list_size(NULL), 0);
	printf("%d (from last %d)\n", ft_list_size(&list_last), 1);
	printf("-done\n");
	free(list_next.data);
	free(list_last.data);
	printf("\n--ft_list_push_front\n");
	push_test = &list;
	ft_list_push_front(&push_test, strdup("toto"));
	printf("added: `%s` (next: %p)\n",
		   (char *)(push_test->data), push_test->next);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	main_2(push_test);
}

void	main_0(void)
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;

	atoi_base("dommage", "+toujours");
	atoi_base("dommage", "-stop");
	atoi_base("dommage", "  \t\nca suffit");
	atoi_base("    +42", "0123456789");
	atoi_base("    -42", "0123456789");
	atoi_base("    42", "0123456789");
	atoi_base("  \t\n\r\v\f  42", "0123456789");
	atoi_base("  \t\n\r\v\f  -42", "0123456789");
	atoi_base("42FINIS !", "0123456789");
	atoi_base("-42FINIS !", "0123456789");
	atoi_base("C'est dommage42", "0123456789");
	printf("-done\n");
	list.data = strdup("toto");
	list.next = &list_next;
	list_next.data = strdup("bar");
	list_next.next = &list_last;
	list_last.data = strdup("monkaS");
	list_last.next = NULL;
	main_1(list, list_next, list_last, &list);
}
