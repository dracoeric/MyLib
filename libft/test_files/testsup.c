/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:59:55 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 14:44:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	void	*ptr;
	void	*ptr2;
	size_t	n;
	int		nb;
	char	*stra;
	char	**split;

	nb = 0;

//Test de memalloc
	printf("\n___===   Test de memalloc   ===___\n");
	n = 0;
	ptr = malloc(n);
	ft_bzero(ptr, n);
	ptr2 = ft_memalloc(n);
	printf("\nmemcmp pour n = %zu : %d entre memalloc et malloc + bzero\n", n, ft_memcmp(ptr, ptr2,n));
	n = 2;
	ptr = malloc(n);
	ft_bzero(ptr, n);
	ptr2 = ft_memalloc(n);
	printf("\nmemcmp pour n = %zu : %d entre memalloc et malloc + bzero\n", n, ft_memcmp(ptr, ptr2,n));
	n = 5;
	ptr = malloc(n);
	ft_bzero(ptr, n);
	ptr2 = ft_memalloc(n);
	printf("\nmemcmp pour n = %zu : %d entre memalloc et malloc + bzero\n", n, ft_memcmp(ptr, ptr2,n));
	n = 10;
	ptr = malloc(n);
	ft_bzero(ptr, n);
	ptr2 = ft_memalloc(n);
	printf("\nmemcmp pour n = %zu : %d entre memalloc et malloc + bzero\n", n, ft_memcmp(ptr, ptr2,n));
	printf("\n\n\n");

//Test de memdel
	printf("\n___===   Test de memdel   ===___\n");
	ft_memdel(&ptr2);
	printf("Liberation de ptr2\n ptr2 = %s\n", ptr2);
	printf("\n\n\n");

//Test de strnew
	printf("\n___===   Test de strnew   ===___\n");
	stra = ft_strnew(10);
	printf("nouveau str:\n");
	while (nb < 10)
	{
		if (stra[nb] == '\0')
			printf("'\\0' ");
		nb++;
	}
	nb = 0;
	printf("\n\n\n\n");

//Test de strclr
	printf("\n___===   Test de strclr   ===___\n");
	ft_memset(stra, 48, 9);
	printf("stra remplis de zero\nstra  = %s\n", stra);
	ft_strclr(stra);
	printf("stra apres clear\n");
	while (nb < 10)
	{
		if (stra[nb] == '\0')
			printf("'\\0' ");
		nb++;
	}
	nb = 0;
	printf("\n\n\n");

//Test de striter
	printf("\n___===   Test de striter   ===___\n");
	stra = ft_strcpy(stra, "caca MOu");
	printf("str = %s\n", stra);
	ft_striter(stra, &ft_strtoupper);
	printf("Application de toupper\nstr = %s\n", stra);
	ft_striter(stra, &ft_strtolower);
	printf("Application de tolower\nstr = %s\n", stra);
	printf("\n\n\n");

//Test de striteri
	printf("\n___===   Test de striteri   ===___\n");
	stra = ft_strcpy(stra, "caca MOu");
	printf("str = %s\nApplication de ft_striteri avec ft_charatpos\n", stra);
	ft_striteri(stra, &ft_charatpos);
	printf("\n\n\n");

//Test de strmap
	printf("\n___===   Test de strmap   ===___\n");
	stra = ft_strcpy(stra, "caca MOu");
	printf("str = %s\nCreation du string a majuscule inverse avec ft_charrevcap\n", stra);
	printf("strrevcap = %s\n", ft_strmap(stra, &ft_charrevcap));
	printf("\n\n\n");

//Test de strmapi
	printf("\n___===   Test de strmapi   ===___\n");
	stra = ft_strcpy(stra, "caca MOu");
	printf("str = %s\nCreation du string avec ft_charcapifeven\n", stra);
	printf("strcapeveb = %s\n", ft_strmapi(stra, &ft_charcapifeven));
	printf("\n\n\n");
	
//Test de strdel
	printf("\n___===   Test de strdel   ===___\n");
	ft_strdel(&stra);
	printf("Liberation de str2\n stra = %s\n", stra);
	printf("\n\n\n");

//Test de strequ et strnequ
	printf("\n___===   Test de strequ et strnequ   ===___\n");
	nb = 0;
	printf(" 'caca' et 'caca ' sont egaux ? : %d\n", ft_strequ("caca", "caca "));
	printf(" 'caca' et 'caca' sont egaux ? : %d\n", ft_strequ("caca", "caca"));
	printf(" '' et '' sont egaux ? : %d\n", ft_strequ("", ""));
	printf(" 'caca' et 'caca mou' sont egaux pour n = 4? : %d\n", ft_strnequ("caca", "caca mou", 4));
	printf(" 'caca' et 'caca' sont egaux pour n = 5? : %d\n", ft_strnequ("caca", "caca", 5));
	printf(" 'caca' et 'caca mou' sont egaux pour n = 5? : %d\n", ft_strnequ("caca", "caca mou", 5));
	printf(" 'caca' et 'pipi' sont egaux pour n = 0? : %d\n", ft_strnequ("caca", "pipi", 0));
	printf("\n\n\n");

//Test de strsub
	printf("\n___===   Test de strsub   ===___\n");
	stra = ft_strnew(20);
	stra = ft_strcpy(stra, "caca MOu");
	printf("src = %s\n", stra);
	printf("sub de 1 d'une longueur 3 : %s\n", ft_strsub(stra, 1, 3));
	printf("sub de 3 d'une longueur 3 : %s\n", ft_strsub(stra, 3, 3));
	printf("sub de 0 d'une longueur 0 : %s\n", ft_strsub(stra, 0, 0));
	printf("sub de 1 d'une longueur 1 : %s\n", ft_strsub(stra, 1, 1));\
	printf("\n\n\n");

//Test de strjoin
	printf("\n___===   Test de strjoin   ===___\n");
	printf("Jointure de \n'il faut ' \net de \n'bien s'essuyer les fesses'\n%s\n",ft_strjoin("il faut ", "bien s'essuyer les fesses"));
	printf("\n\n\n");

//Test de strtrim
	printf("\n___===   Test de strtrim   ===___\n");
	stra = ft_strnew(20);
	stra = ft_strcpy(stra, "   caca MOu   ");
	printf("\nTriming of str = '%s'\n strtrim = '%s'\n", stra, ft_strtrim(stra));
	stra = ft_strcpy(stra, "caca MOu   ");
	printf("\nTriming of str = '%s'\n strtrim = '%s'\n", stra, ft_strtrim(stra));
	stra = ft_strcpy(stra, "   caca MOu");
	printf("\nTriming of str = '%s'\n strtrim = '%s'\n", stra, ft_strtrim(stra));
	stra = ft_strcpy(stra, "caca MOu");
	printf("\nTriming of str = '%s'\n strtrim = '%s'\n", stra, ft_strtrim(stra));
	stra = ft_strcpy(stra, "        ");
	printf("\nTriming of str = '%s'\n strtrim = '%s'\n", stra, ft_strtrim(stra));
	stra = ft_strcpy(stra, "");
	printf("\nTriming of str = '%s'\n strtrim = '%s'\n", stra, ft_strtrim(stra));
	printf("\n\n\n");

//Test de strsplit
	printf("\n___===   Test de strsplit   ===___\n");
	stra = ft_strcpy(stra, "   caca MOu   ");
	printf("\nsrc = '%s'\n\nsplit pour ' ':\n", stra);
	split = ft_strsplit(stra, ' ');
	ft_printstrsplit(split);
	printf("\nsplit pour 'c':\n");
	split = ft_strsplit(stra, 'c');
	ft_printstrsplit(split);
	printf("\nsplit pour '\\0':\n");
	split = ft_strsplit(stra, '\0');
	ft_printstrsplit(split);
	printf("\n\n\n");

//Test de itoa
	printf("\n___===   Test de itoa   ===___\n");
	nb = 0;
	printf("\n n = %d\nitoa = '%s'\n", nb, ft_itoa(nb));
	nb = 2147483647;
	printf("\n n = %d\nitoa = '%s'\n", nb, ft_itoa(nb));
	nb = -2147483648;
	printf("\n n = %d\nitoa = '%s'\n", nb, ft_itoa(nb));
	nb = 7812563;
	printf("\n n = %d\nitoa = '%s'\n", nb, ft_itoa(nb));
	nb = 10000000;
	printf("\n n = %d\nitoa = '%s'\n", nb, ft_itoa(nb));
	printf("\n\n\n");

//Test de putnbr
	printf("\n___===   Test de putnbr   ===___\n");
	nb = 0;
	printf(" n = %d\n", nb);
	write(1, "putnbr = ", 9);
	ft_putnbr(nb);
	nb = -1234;
	printf("\n n = %d\n", nb);
	write(1, "putnbr = ", 9);
	ft_putnbr(nb);
	nb = 2147483647;
	printf("\n n = %d\n", nb);
	write(1, "putnbr = ", 9);
	ft_putnbr(nb);
	nb = -2147483648;
	printf("\n n = %d\n", nb);
	write(1, "putnbr = ", 9);
	ft_putnbr(nb);
	nb = 123145;
	printf("\n n = %d\n", nb);
	write(1, "putnbr = ", 9);
	ft_putnbr(nb);
	nb = -100000;
	printf("\n n = %d\n", nb);
	write(1, "putnbr = ", 9);
	ft_putnbr(nb);
	nb = 0;
	printf("\n\n\n");



	return (0);
}
