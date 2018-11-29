/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlibc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:09:37 by erli              #+#    #+#             */
/*   Updated: 2018/11/07 17:51:18 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int		main(void)
{
	char str[15];
	char strc[15];
	char dest[10];
	char destc[10];
	char *stra;
	char *strb;
	char *strbig;

//Test Strlen
	printf("___=== Test de ft_strlen ===___\n");
	printf("Longueur de 'caca' ft = %zu   libc = %lu\n", ft_strlen("caca"), strlen("caca"));
	printf("Longueur de '' ft = %zu   libc = %lu\n", ft_strlen(""), strlen(""));
	printf("Longueur de 'cacafumant' ft = %zu   libc = %lu\n", ft_strlen("cacafumant"), strlen("cacafumant"));
	printf("\n\n\n");


//Test de Strdup
	printf("___=== Test de ft_strdup ===___\n");
	printf(" src = ''\n");
	printf("%s\n", ft_strdup(""));
	printf("%s\n", strdup(""));
	printf(" src = 'caca'\n");
	printf("%s\n", ft_strdup("caca"));
	printf("%s\n", strdup("caca"));
	printf(" src = 'olelele'\n");
	printf("%s\n", ft_strdup("olelele"));
	printf("%s\n", strdup("olelele"));
	printf(" src = 'qwertyuiopasdfghjkl;:'\n");
	printf("%s\n", ft_strdup("qwertyuiopasdfghjkl;:"));
	printf("%s\n", strdup("qwertyuiopasdfghjkl;:"));
	printf("\n\n\n");


//Test de memset
	printf("___=== Test de ft_memeset ===___\n");
	str[14] = '\0';
	strc[14] = '\0';	
	printf("Ecrire 9 'Z'\n");
	printf("ft %s\n", ft_memset(str, 90, 14));
	printf("ft %s\n", memset(strc, 90, 14));
	printf("Ecrire 7 'Y'\n");	
	printf("%s\n", ft_memset(str, 89, 7));
	printf("libc %s\n", memset(strc, 89, 7));
	printf("pour length = 0\n");
	printf("ft %s\n", ft_memset(str, 90, 0));
	printf("%s\n", memset(strc, 90, 0));
	printf("\n\n\n");


//Test de bzero
	printf("___=== Test de ft_bzero ===___\n");
	printf("Si length = 0\n");
	ft_bzero(str, 0);
	printf("str = %s\n", str);
	bzero(strc, 0);
	printf("strc = %s\n", strc);
	printf("Ecrire 2 byte nul\n");
	ft_bzero(str, 2);
	bzero(strc,2);
	printf("str = %s\n", str);
	printf("str[1] = %c\n", str[1]);
	printf("str[2] = %c\n", str[2]);
	printf("strc = %s\n", strc);
	printf("strc[1] = %c\n", strc[1]);
	printf("strc[2] = %c\n", strc[2]);
	printf("\n\n\n");


//Test de memcpy
	printf("___=== Test de ft_memcpy ===___\n");
	ft_bzero(dest, 10);
	bzero(destc, 10);
	ft_memset(str, 68, 2);
	memset(strc, 68, 2);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("copy de 0 octet\n");
	printf(" ft = %s\n", ft_memcpy(dest, str, 0));
	printf(" c = %s\n", memcpy(destc, strc, 0));
	printf("copy de 1 octet\n");
	printf(" ft = %s\n", ft_memcpy(dest, str, 1));
	printf(" c = %s\n", memcpy(destc, strc, 1));
	//pour 10 octet il faut tester sur le meme pour eviter l'overlap de dest et destc
	printf("copy de 10 octet\n");
	printf(" ft = %s\n", ft_memcpy(dest, str, 10));
	ft_bzero(dest, 10);
	printf(" c = %s\n", memcpy(dest, str, 10));
	printf("\n\n\n");
/*	printf("copy de 12 octet\n");
	printf(" ft = %s\n", ft_memcpy(dest, str, 12));
	ft_bzero(dest, 10);
	ft_memset(str, 90, 14);
	ft_memset(str, 89, 7);
	ft_memset(str, 68, 2);
	printf(" c = %s\n", memcpy(dest, strc, 12));
	printf("\n\n\n");*/


	
//Test de memccpy
	printf("___=== Test de ft_memccpy ===___\n");
	ft_memset(dest, 48, 9);
	memset(destc, 48, 9);
	dest[9] = 0;
	destc[9] = 0;
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("Copy de n = 5 pour charactere introuvable\n");
	printf("ft pointeur = %s\n", (char *)ft_memccpy(dest, str, 48, 5));
	printf("ft dest = %s\n", dest);
	printf("libc pointeur = %s\n", (char *)memccpy(destc, str, 48, 5));
	printf("libc dest = %s\n", destc);
	ft_memset(dest, 48, 9);
	memset(destc, 48, 9);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("Copy de n = 5 pour character = Y\n");
	printf("ft pointeur = %s\n", (char *)ft_memccpy(dest, str, 89, 5));
	printf("ft dest = %s\n", dest);
	printf("libc pointeur = %s\n", (char *)memccpy(destc, str, 89, 5));
	printf("libc dest = %s\n", destc);
	ft_memset(dest, 48, 9);
	memset(destc, 48, 9);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("Copy de n = 9 pour character = Z\n");
	printf("ft pointeur = %s\n", (char *)ft_memccpy(dest, str, 90, 9));
	printf("ft dest = %s\n", dest);
	printf("libc pointeur = %s\n", (char *)memccpy(destc, str, 90, 9));
	printf("libc dest = %s\n", destc);
	printf("\n\n\n");

/*	ft_memset(dest, 48, 9);
	memset(destc, 48, 9);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("Copy de n = 11 pour character = Z\n");
	printf("ft pointeur = %s\n", (char *)ft_memccpy(dest, str, 50, 11));
	printf("ft dest = %s\n", dest);
	ft_memset(dest, 48, 9);
	dest[9] = 0;
	ft_memset(str, 90, 14);
	ft_memset(str, 89, 7);
	ft_memset(str, 68, 2);
	printf("libc pointeur = %s\n", (char *)memccpy(dest, str, 50, 11));
	printf("libc dest = %s\n", dest);
	printf("\n\n\n");*/

//Test de memmove
	printf("___=== Test de ft_memmove ===___\n");
	ft_memset(dest, 0, 10);
	memset(destc, 0, 10);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("dest 'vide' et n = 3\ndest = %s\n", ft_memmove(dest, str, 3));
	printf("destc 'vide' et n = 3\ndestc = %s\n", memmove(destc, strc, 3));
	ft_memset(dest, 48, 9);
	memset(destc, 48, 9);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("dest '0' et n = 3\ndest = %s\n", ft_memmove(dest, str, 3));
	printf("destc '0' et n = 3\ndestc = %s\n", memmove(destc, strc, 3));
	ft_memset(dest, 0, 10);
	memset(destc, 0, 10);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("destc 'vide' et n = 10\ndestc = %s \n", memmove(dest, str, 10));
	printf("dest 'vide' et n = 10\ndest = %s\n", ft_memmove(dest, str, 10));
	printf("\n\n\n");
/*	ft_memset(dest, 0, 9);
	memset(destc, 0, 9);
	printf("ft src = %s, libc src = %s, dest = %s, destc = %s\n", str, strc, dest, destc);
	printf("dest 'vide' et n = 11\ndest = %s\n", memmove(destc, strc, 11));
	printf("destc 'vide' et n = 11\ndestc = %s\n", memmove(destc, strc, 11));*/

//Test de memchr
	printf("___=== Test de ft_memchr ===___\n");
	printf("ft src = %s\n Recherche de '0' pour n = 5\n", str);
	printf("result ft = %s\nresult libc = %s\n", ft_memchr(str, 48, 5), memchr(str, 48, 5));
	printf("ft src = %s\n Recherche de '0' pour n = 20\n", str);
	printf("result ft = %s\nresult libc = %s\n", ft_memchr(str, 48, 20), memchr(str, 48, 20));
	printf("ft src = %s\n Recherche de 'D' pour n = 5\n", str);
	printf("result ft = %s\nresult libc = %s\n", ft_memchr(str, 68, 5), memchr(str, 68, 5));
	printf("ft src = %s\n Recherche de 'Z' pour n = 15\n", str);
	printf("result ft = %s\nresult libc = %s\n", ft_memchr(str, 90, 15), memchr(str, 90, 15));
	printf("ft src = %s\n Recherche de '0' pour n = 15\n", str);
	printf("result ft = %s\nresult libc = %s\n", ft_memchr(str, 48, 15), memchr(str, 48, 15));
	printf("\n\n\n");

//Test de memcmp
	printf("___=== Test de ft_memchmp ===___\n");
	stra = "oleleL";
	strb = "oleLeL";
	printf ("\nsrc = %s, srcs = %s\n", stra, strb);
	printf("\npour n = 3 \ndiff ft = %d\ndiff libc = %d\n", ft_memcmp(stra, strb, 3), memcmp(stra, strb, 3));
	printf("\npour n = 5 \ndiff ft = %d\ndiff libc = %d\n", ft_memcmp(stra, strb, 5), memcmp(stra, strb, 5));
	stra = "";
	strb = "";
	printf("\npour n = 0 \ndiff ft = %d\ndiff libc = %d\n", ft_memcmp(stra, strb, 0), memcmp(stra, strb, 0));
	printf("\n\n\n");

//Test de strcpy
	printf("___=== Test de ft_strcpy ===___\n");
	ft_bzero(dest, 10);
	stra = "oleleLert";
	strb = "oleLeLert";
	printf("\nsrc = %s, dest = %s\n", stra, dest);
	printf("ft dst = %s\n", ft_strcpy(dest, stra));
	ft_bzero(dest, 10);
	printf("src = %s, dest = %s\n", strb, dest);
	printf("libc dst = %s\n", strcpy(dest, strb));
	ft_bzero(dest, 10);
	stra = "olel";
	strb = "oleL";
	printf("\nsrc = %s, dest = %s\n", stra, dest);
	printf("ft dst = %s\n", ft_strcpy(dest, stra));
	ft_bzero(dest, 10);
	printf("src = %s, dest = %s\n", strb, dest);
	printf("libc dst = %s\n", strcpy(dest, strb));
	ft_bzero(dest, 10);
	stra = "";
	strb = "";
	printf("\nsrc = %s, dest = %s\n", stra, dest);
	printf("ft dst = %s\n", ft_strcpy(dest, stra));
	ft_bzero(dest, 10);
	printf("src = %s, dest = %s\n", strb, dest);
	printf("libc dst = %s\n", strcpy(dest, strb));
	printf("\n\n\n");

//Test de strncpy
	printf("___=== Test de ft_strncpy ===___\n");
	ft_bzero(dest, 10);
	stra = "oleleLerti";
	strb = "oleLeLerti";
	printf("\nsrc = %s, dest = %s, n = 10\n", stra, dest);
	printf("ft dst = %s\n", ft_strncpy(dest, stra, 10));
	ft_bzero(dest, 10);
	printf("src = %s, dest = %s, n = 10\n", strb, dest);
	printf("libc dst = %s\n", strncpy(dest, strb, 10));
	ft_bzero(dest, 10);
	stra = "olel";
	strb = "oleL";
	printf("\nsrc = %s, dest = %s, n = 8\n", stra, dest);
	printf("ft dst = %s\n", ft_strncpy(dest, stra, 8));
	ft_bzero(dest, 10);
	printf("src = %s, dest = %s, n = 8\n", strb, dest);
	printf("libc dst = %s\n", strncpy(dest, strb, 8));
	ft_bzero(dest, 10);
	stra = "";
	strb = "";
	printf("\nsrc = %s, dest = %s, n = 5\n", stra, dest);
	printf("ft dst = %s\n", ft_strncpy(dest, stra, 5));
	ft_bzero(dest, 10);
	printf("src = %s, dest = %s, n = 5\n", strb, dest);
	printf("libc dst = %s\n", strncpy(dest, strb, 5));
	printf("\n\n\n");

//Test de strcat
	if (!(strbig = (char *)malloc(sizeof(char) * 100)))
		return (0);
	printf("___=== Test de ft_strcat ===___\n");
	stra = "oleleLerti";
	strb = "belebele";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s\n", strbig, strb);
	printf("ft dst = %s\n", strcat(strbig, strb));
	stra = "oleleLerti";
	strb = "belebele";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s\n", strbig, strb);
	printf("libc dst = %s\n", strcat(strbig, strb));
	stra = "";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s\n", strbig, strb);
	printf("ft dst = %s\n", ft_strcat(strbig, strb));
	stra = "";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s\n", strbig, strb);
	printf("libc dst = %s\n", strcat(strbig, strb));
	printf("\n\n\n");


//Test de strncat
	printf("___=== Test de ft_strncat ===___\n");
	stra = "oleleLerti";
	strb = "belebele";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s, n = 4\n", strbig, strb);
	printf("ft dst = %s\n", strncat(strbig, strb, 4));
	stra = "oleleLerti";
	strb = "belebele";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s, n = 4\n", strbig, strb);
	printf("libc dst = %s\n", strncat(strbig, strb, 4));
	stra = "";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s, n = 10\n", strbig, strb);
	printf("ft dst = %s\n", ft_strncat(strbig, strb, 10));
	stra = "";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s, n = 10\n", strbig, strb);
	printf("libc dst = %s\n", strncat(strbig, strb, 10));
	printf("\n\n\n");

//Test de strlcat
	printf("___=== Test de ft_strlcat ===___\n");
	stra = "oleleLerti";
	strb = "belebele";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s, n = 4\n", strbig, strb);
	printf("out = %lu\n", strlcat(strbig, strb, 4));
	printf("ft dest = %s\n", strbig); 
	stra = "oleleLerti";
	strb = "belebele";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s, n = 4\n", strbig, strb);
	printf("libc out = %lu\n", strlcat(strbig, strb, 4));
	printf("ft dest = %s\n", strbig); 
	stra = "1234567";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s, n = 10\n", strbig, strb);
	printf("ft out = %lu\n", ft_strlcat(strbig, strb, 10));
	printf("ft dest = %s\n", strbig); 
	stra = "1234567";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s, n = 10\n", strbig, strb);
	printf("libc out = %lu\n", strlcat(strbig, strb, 10));
	printf("ft dest = %s\n", strbig); 
	stra = "1234567";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s, n = 7\n", strbig, strb);
	printf("ft out = %lu\n", ft_strlcat(strbig, strb, 7));
	printf("ft dest = %s\n", strbig); 
	stra = "1234567";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s, n = 7\n", strbig, strb);
	printf("libc out = %lu\n", strlcat(strbig, strb, 7));
	printf("ft dest = %s\n", strbig); 
	stra = "12";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("\nstra = %s, strb = %s, n = 6\n", strbig, strb);
	printf("ft out = %lu\n", ft_strlcat(strbig, strb, 6));
	printf("ft dest = %s\n", strbig); 
	stra = "12";
	strb = "oleL";
	ft_bzero(strbig, 100);
	ft_strcpy(strbig, stra);
	printf("stra = %s, strb = %s, n = 6\n", strbig, strb);
	printf("libc out = %lu\n", strlcat(strbig, strb, 6));
	printf("ft dest = %s\n", strbig); 
	printf("\n\n\n");

//Test de strchr
	printf("___=== Test de ft_strchr ===___\n");
	stra = "12345";
	printf("str = %s\n", stra);
	printf("\n Pour c = '1'\n ft ptr = %s\n libc ptr = %s\n", ft_strchr(stra, 49), strchr(stra, 49));
	printf("\n Pour c = '3'\n ft ptr = %s\n libc ptr = %s\n", ft_strchr(stra, 51), strchr(stra, 51));
	printf("\n Pour c = '\\0'\n ft ptr = %s\n libc ptr = %s\n", ft_strchr(stra, 0), strchr(stra, 0));
	printf("\n Pour c = 'Z'\n ft ptr = %s\n libc ptr = %s\n", ft_strchr(stra, 90), strchr(stra, 90));
	printf("\n\n\n");

//Test de strrchr
	printf("___=== Test de ft_strrchr ===___\n");
	stra = "1234522345";
	printf("str = %s\n", stra);
	printf("\n Pour c = '1'\n ft ptr = %s\n libc ptr = %s\n", ft_strrchr(stra, 49), strrchr(stra, 49));
	printf("\n Pour c = '3'\n ft ptr = %s\n libc ptr = %s\n", ft_strrchr(stra, 51), strrchr(stra, 51));
	printf("\n Pour c = '\\0'\n ft ptr = %s\n libc ptr = %s\n", ft_strrchr(stra, 0), strrchr(stra, 0));
	printf("\n Pour c = 'Z'\n ft ptr = %s\n libc ptr = %s\n", ft_strrchr(stra, 90), strrchr(stra, 90));
	printf("\n\n\n");

//Test de strstr
	printf("___=== Test de ft_strstr ===___\n");
	stra = "1234522345";
	strb = "223";
	printf("\nhaysack = %s,  needle = %s\nft str = %s\nlibc str = %s\n", stra, strb, ft_strstr(stra, strb), strstr(stra, strb));
	stra = "1234522345";
	strb = "jfi";
	printf("\nhaysack = %s,  needle = %s\nft str = %s\nlibc str = %s\n", stra, strb, ft_strstr(stra, strb), strstr(stra, strb));
	stra = "1234522345";
	strb = "";
	printf("\nhaysack = %s,  needle = %s\nft str = %s\nlibc str = %s\n", stra, strb, ft_strstr(stra, strb), strstr(stra, strb));
	stra = "1234522345";
	strb = "23";
	printf("\nhaysack = %s,  needle = %s\nft str = %s\nlibc str = %s\n", stra, strb, ft_strstr(stra, strb), strstr(stra, strb));
	printf("\n\n\n");

//Test de strnstr
	printf("___=== Test de ft_strnstr ===___\n");
	stra = "1234522345";
	strb = "223";
	printf("\nhaysack = %s,  needle = %s n = 10\nft str = %s\nlibc str = %s\n", stra, strb, ft_strnstr(stra, strb, 10), strnstr(stra, strb, 10));
	stra = "1234522345";
	strb = "223";
	printf("\nhaysack = %s,  needle = %s n = 5\nft str = %s\nlibc str = %s\n", stra, strb, ft_strnstr(stra, strb, 5), strnstr(stra, strb, 5));
	stra = "1234522345";
	strb = "223";
	printf("\nhaysack = %s,  needle = %s n = 15\nft str = %s\nlibc str = %s\n", stra, strb, ft_strnstr(stra, strb, 15), strnstr(stra, strb, 15));
	stra = "1234522345";
	strb = "223";
	printf("\nhaysack = %s,  needle = %s n = 0\nft str = %s\nlibc str = %s\n", stra, strb, ft_strnstr(stra, strb, 0), strnstr(stra, strb, 0));
	stra = "1234522345";
	strb = "";
	printf("\nhaysack = %s,  needle = %s n = 0\nft str = %s\nlibc str = %s\n", stra, strb, ft_strnstr(stra, strb, 0), strnstr(stra, strb, 0));
	printf("\n\n\n");

//Test de strcmp
	printf("___=== Test de ft_strcmp ===___\n");
	stra = "12345";
	strb = "123";
	printf("\ns1 = %s, s2 = %s\nftcmp = %d\nlibc cmp = %d\n", stra, strb, ft_strcmp(stra, strb), strcmp(stra, strb));
	stra = "12345";
	strb = "12345";
	printf("\ns1 = %s, s2 = %s\nftcmp = %d\nlibc cmp = %d\n", stra, strb, ft_strcmp(stra, strb), strcmp(stra, strb));
	stra = "12";
	strb = "123";
	printf("\ns1 = %s, s2 = %s\nftcmp = %d\nlibc cmp = %d\n", stra, strb, ft_strcmp(stra, strb), strcmp(stra, strb));
	printf("\n\n\n");

//Test de strncmp
	printf("___=== Test de ft_strncmp ===___\n");
	stra = "12345";
	strb = "123";
	printf("\ns1 = %s, s2 = %s n = 6\nftcmp = %d\nlibc cmp = %d\n", stra, strb, ft_strncmp(stra, strb, 6), strncmp(stra, strb, 6));
	stra = "12345";
	strb = "123";
	printf("\ns1 = %s, s2 = %s n = 5\nftcmp = %d\nlibc cmp = %d\n", stra, strb, ft_strncmp(stra, strb, 5), strncmp(stra, strb, 5));
	stra = "12345";
	strb = "123";
	printf("\ns1 = %s, s2 = %s n = 3\nftcmp = %d\nlibc cmp = %d\n", stra, strb, ft_strncmp(stra, strb, 3), strncmp(stra, strb, 3));
	printf("\n\n\n");


//Test de atoi
	printf("___=== Test de ft_atoi ===___\n");
	stra = "12345";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "   12345";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "  -12345";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "    +12345";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "  123a45";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "-2147483648";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "2147483647";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "2147483648";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "12345678901";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	stra = "-12345678901";
	printf("\nstr = .%s\nft nb = %d\n, libc nb = %d\n", stra, ft_atoi(stra), atoi(stra));
	printf("\n\n\n");

//Test de isalpha
	printf("___=== Test de ft_isalpha ===___\n");
	printf("\n n = 90\nft = %d\nlibc = %d\n", ft_isalpha(90), isalpha(90));
	printf("\n n = 91\nft = %d\nlibc = %d\n", ft_isalpha(91), isalpha(91));
	printf("\n n = 50\nft = %d\nlibc = %d\n", ft_isalpha(50), isalpha(50));
	printf("\n n = 55\nft = %d\nlibc = %d\n", ft_isalpha(55), isalpha(55));
	printf("\n n = 120\nft = %d\nlibc = %d\n", ft_isalpha(120), isalpha(120));
	printf("\n n = 320\nft = %d\nlibc = %d\n", ft_isalpha(320), isalpha(320));
	printf("\n\n\n");
	return (0);
}
