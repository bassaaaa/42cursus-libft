/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:22:42 by tsito             #+#    #+#             */
/*   Updated: 2026/04/25 17:49:40 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

#define TEST_CTYPE(fn, c) printf(#fn "(" #c "): ft = %d std = %d\n", ft_##fn(c), fn(c))

static void   dump(unsigned char *buf, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        printf(" %02X", buf[i]);
        i++;
    }
    printf("\n");
}

int	main(void)
{
	printf("%s : %s\n", "ft", "lib");
	printf("\n-----isalpha-----\n");
	TEST_CTYPE(isalpha, '@');
	TEST_CTYPE(isalpha, 'A');
	TEST_CTYPE(isalpha, 'Z');
	TEST_CTYPE(isalpha, '[');
	TEST_CTYPE(isalpha, '`');
	TEST_CTYPE(isalpha, 'a');
	TEST_CTYPE(isalpha, 'z');
	TEST_CTYPE(isalpha, '{');
	TEST_CTYPE(isalpha, '0');
	TEST_CTYPE(isalpha, ' ');
	TEST_CTYPE(isalpha, '\0');
	TEST_CTYPE(isalpha, 127);
	TEST_CTYPE(isalpha, -1);
	TEST_CTYPE(isalpha, 128);
	printf("\n-----isdigit-----\n");
	TEST_CTYPE(isdigit, '/');
	TEST_CTYPE(isdigit, '0');
	TEST_CTYPE(isdigit, '9');
	TEST_CTYPE(isdigit, ':');
	TEST_CTYPE(isdigit, ' ');
	TEST_CTYPE(isdigit, '\0');
	TEST_CTYPE(isdigit, 127);
	TEST_CTYPE(isdigit, -1);
	TEST_CTYPE(isdigit, 128);
	printf("\n-----isalnum-----\n");
	TEST_CTYPE(isalnum, '@');
	TEST_CTYPE(isalnum, 'A');
	TEST_CTYPE(isalnum, 'Z');
	TEST_CTYPE(isalnum, '[');
	TEST_CTYPE(isalnum, '`');
	TEST_CTYPE(isalnum, 'a');
	TEST_CTYPE(isalnum, 'z');
	TEST_CTYPE(isalnum, '{');
	TEST_CTYPE(isalnum, '/');
	TEST_CTYPE(isalnum, '0');
	TEST_CTYPE(isalnum, '9');
	TEST_CTYPE(isalnum, ':');
	TEST_CTYPE(isalnum, ' ');
	TEST_CTYPE(isalnum, '\0');
	TEST_CTYPE(isalnum, 127);
	TEST_CTYPE(isalnum, -1);
	TEST_CTYPE(isalnum, 128);
	printf("\n-----isascii-----\n");
	TEST_CTYPE(isascii, -1);
	TEST_CTYPE(isascii, 0);
	TEST_CTYPE(isascii, 127);
	TEST_CTYPE(isascii, 128);
	printf("\n-----isprint-----\n");
	TEST_CTYPE(isprint, -1);
	TEST_CTYPE(isprint, 31);
	TEST_CTYPE(isprint, 32);
	TEST_CTYPE(isprint, 126);
	TEST_CTYPE(isprint, 127);
	TEST_CTYPE(isprint, 128);
	printf("\n-----strlen-----\n");
	{
        const char	*cases[] = {"", "a", "hello", NULL};
        size_t		i = 0;
		while (cases[i])
		{
			printf("strlen(\"%s\"): ft = %zu std = %zu\n", cases[i],
				ft_strlen(cases[i]), strlen(cases[i]));
			i++;
		}
		printf("strlen(\"a\\0b\"): ft = %zu std = %zu\n", ft_strlen("a\0b"),
			strlen("a\0b"));
	}
	printf("\n-----memset-----\n");
	{
        unsigned char     buf1[8];
        unsigned char     buf2[8];
        size_t            i = 0;

        while (i < 8)
        {
            buf1[i] = 0xAA;
            buf2[i] = 0xAA;
            i++;
        }
        //case 1: len = 0
        ft_memset(buf1, 'a', 0);
        memset(buf2, 'a', 0);
        printf("c='a' len=0\n  ft :");
        dump(buf1, 8);
        printf("  std:");
        dump(buf2, 8);
        // case 2: len = 4
        ft_memset(buf1, 'a', 4);
        memset(buf2, 'a', 4);
        printf("c='a' len=4\n  ft :");
        dump(buf1, 8);
        printf("  std:");
        dump(buf2, 8);
        //case 3: c = 256
        ft_memset(buf1, 256, 8);
        memset(buf2, 256, 8);
        printf("c=256 len=8\n  ft :");
        dump(buf1, 8);
        printf("  std:");
        dump(buf2, 8);
    }
	printf("\n-----bzero-----\n");
    {
        unsigned char     buf1[8];
        unsigned char     buf2[8];
        size_t            i = 0;

        while (i < 8)
        {
            buf1[i] = 0xAA;
            buf2[i] = 0xAA;
            i++;
        }
        // case 1: len = 0
        ft_bzero(buf1, 0);
        bzero(buf2, 0);
        printf("len = 0\n  ft :");
        dump(buf1, 8);
        printf("  std:");
        dump(buf2, 8);
        // case 1: len = 4
        ft_bzero(buf1, 4);
        bzero(buf2, 4);
        printf("len = 4\n  ft :");
        dump(buf1, 8);
        printf("  std:");
        dump(buf2, 8);
        // case 2: len = 8
        ft_bzero(buf1, 8);
        bzero(buf2, 8);
        printf("len = 8\n  ft :");
        dump(buf1, 8);
        printf("  std:");
        dump(buf2, 8);
    }
	printf("\n-----memcpy----\n");
    {
        unsigned char     dst1[8];
        unsigned char     dst2[8];
        unsigned char     src[] = {0x11, 0x22, 0x00, 0x44, 0x55};
        size_t            i = 0;
        void *ret1;
        void *ret2;

        while (i < 8)
        {
            dst1[i] = 0xAA;
            dst2[i] = 0xAA;
            i++;
        }
        ret1 = ft_memcpy(dst1, src, 0);
        ret2 = memcpy(dst2, src, 0);
        printf("len=0\n  ret-dst (expect 0): ft=%ld std=%ld\n", (long)((char *)ret1 - (char *)dst1), (long)((char *)ret2 - (char *)dst2));
        printf("  ft : ret = ");
        dump(ret1, 8);
        printf("  ft : dst = ");
        dump(dst1, 8);
        printf("  std: ret = ");
        dump(ret2, 8);
        printf("  std: dst = ");
        dump(dst2, 8);

        ret1 = ft_memcpy(dst1, src, 5);
        ret2 = memcpy(dst2, src, 5);
        printf("len=5\n  ret-dst (expect 0): ft=%ld std=%ld\n", (long)((char *)ret1 - (char *)dst1), (long)((char *)ret2 - (char *)dst2));
        printf("  ft : ret = ");
        dump(ret1, 8);
        printf("  ft : dst = ");
        dump(dst1, 8);
        printf("  std: ret = ");
        dump(ret2, 8);
        printf("  std: dst = ");
        dump(dst2, 8);
    }
	printf("\n-----memmove-----\n");
    {
        unsigned char     buf1[16];
        unsigned char     buf2[16];
        // unsigned char     src[] = {0x11, 0x22, 0x00, 0x44, 0x55};
        size_t            i = 0;
        void *ret1;
        void *ret2;

        while (i < 8)
        {
            buf1[i] = 'A' + i;
            buf2[i] = 'A' + i;
            i++;
        }
        while (i < 16)
        {
            buf1[i] = 0xAA;
            buf2[i] = 0xAA;
            i++;
        }

        // len = 0
        printf("len = 0\n");
        printf("dst:       ");
        dump(buf1 + 2, 8);
        printf("src: ");
        dump(buf1, 8);
        ret1 = ft_memmove(buf1 + 2, buf1, 0);
        ret2 = memmove(buf2 + 2, buf2, 0);
        printf("  ret-dst (expect 0): ft=%ld std=%ld\n", (long)((char *)ret1 - (char *)(buf1 + 2)), (long)((char *)ret2 - (char *)(buf2 + 2)));
        printf("  ft : ret = ");
        dump(ret1, 8);
        printf("  ft : dst = ");
        dump(buf1 + 2, 8);
        printf("  std: ret = ");
        dump(ret2, 8);
        printf("  std: dst = ");
        dump(buf2 + 2, 8);
        printf("\n");

        // dst前方重複
        printf("dst前方重複, len=5\n");
        printf("dst:       ");
        dump(buf1 + 2, 8);
        printf("src: ");
        dump(buf1, 8);
        ret1 = ft_memmove(buf1 + 2, buf1, 5);
        ret2 = memmove(buf2 + 2, buf2, 5);
        printf("  ret-dst (expect 0): ft=%ld std=%ld\n", (long)((char *)ret1 - (char *)(buf1 + 2)), (long)((char *)ret2 - (char *)(buf2 + 2)));
        printf("  ft : ret = ");
        dump(ret1, 8);
        printf("  ft : dst = ");
        dump(buf1 + 2, 8);
        printf("  std: ret = ");
        dump(ret2, 8);
        printf("  std: dst = ");
        dump(buf2 + 2, 8);
        printf("\n");

        // dst後方重複
        i = 0;
        while (i < 8)
        {
            buf1[i] = 'A' + i;
            buf2[i] = 'A' + i;
            i++;
        }
        printf("dsst後方重複, len=5\n");
        printf("dst: ");
        dump(buf1, 8);
        printf("src:       ");
        dump(buf1 + 2, 8);
        ret1 = ft_memmove(buf1, buf1 + 2, 5);
        ret2 = memmove(buf2, buf2 + 2, 5);
        printf("  ret-dst (expect 0): ft=%ld std=%ld\n", (long)((char *)ret1 - (char *)buf1), (long)((char *)ret2 - (char *)buf2));
        printf("  ft : ret = ");
        dump(ret1, 8);
        printf("  ft : dst = ");
        dump(buf1, 8);
        printf("  std: ret = ");
        dump(ret2, 8);
        printf("  std: dst = ");
        dump(buf2, 8);
    }
	printf("\n-----strlcpy-----\n");
    {
        char    dst1[8];
        char    dst2[8];
        char    src[] = "hello";
        size_t  ret1;
        size_t  ret2;

        // dstsize == sizeof(dst)
        ft_bzero(dst1, sizeof(dst1));
        ft_bzero(dst2, sizeof(dst2));
        ret1 = ft_strlcpy(dst1, src, sizeof(dst1));
        ret2 = strlcpy(dst2, src, sizeof(dst2));
        printf("[case 1] dstsize == sizeof(dst)\n");
        printf("  ret: ft=%zu std=%zu\n", ret1, ret2);
        printf("  dst: ft=\"%s\" std=\"%s\"\n", dst1, dst2);

        //dstsize < sizeof(dst)
        ft_bzero(dst1, sizeof(dst1));
        ft_bzero(dst2, sizeof(dst2));
        ret1 = ft_strlcpy(dst1, src, 3);
        ret2 = strlcpy(dst2, src, 3);
        printf("[case 2] dstsize < sizeof(dst)\n");
        printf("  ret: ft=%zu std=%zu\n", ret1, ret2);
        printf("  dst: ft=\"%s\" std=\"%s\"\n", dst1, dst2);

        // dstsize = 0
        ft_memset(dst1, 0xAA, sizeof(dst1));
        ft_memset(dst2, 0xAA, sizeof(dst2));
        ret1 = ft_strlcpy(dst1, src, 0);
        ret2 = strlcpy(dst2, src, 0);
        printf("[case 3] dstsize = 0\n");
        printf("  ret: ft=%zu std=%zu\n", ret1, ret2);
        printf("  dst raw ft :");
        dump((unsigned char *)dst1, sizeof(dst1));
        printf("  dst raw std:");
        dump((unsigned char *)dst2, sizeof(dst2));

        // src == ""
        ft_memset(dst1, 0xAA, sizeof(dst1));
        ft_memset(dst2, 0xAA, sizeof(dst2));
        ret1 = ft_strlcpy(dst1, "", sizeof(dst1));
        ret2 = strlcpy(dst2, "", sizeof(dst2));
        printf("[case 4] src == \"\"\n");
        printf("  ret: ft=%zu std=%zu\n", ret1, ret2);
        printf("  dst raw ft :");
        dump((unsigned char *)dst1, sizeof(dst1));
        printf("  dst raw std:");
        dump((unsigned char *)dst2, sizeof(dst2));
    }
	printf("\n----strlcat-----\n");
	printf("\n----toupper-----\n");
	printf("\n----tolower-----\n");
	printf("\n----strchr-----\n");
	printf("\n----strncmp-----\n");
	printf("\n----memchr-----\n");
	printf("\n----memcmp-----\n");
	printf("\n----strnstr-----\n");
	printf("\n----atoi-----\n");
	printf("\n----calloc-----\n");
	printf("\n----strdup-----\n");
	printf("\n----substr-----\n");
	printf("\n----strjoin-----\n");
	printf("\n----strtrim-----\n");
	printf("\n----split-----\n");
	printf("\n----itoa-----\n");
	printf("\n----strmapi-----\n");
	printf("\n----striteri-----\n");
	printf("\n----putchar_fd-----\n");
	printf("\n----putstr_fd-----\n");
	printf("\n----putendl_fd-----\n");
	printf("\n----putnbr_fd-----\n");
	printf("\n----lstnew-----\n");
	printf("\n----lstadd_front-----\n");
	printf("\n----lstsize-----\n");
	printf("\n----lstlast-----\n");
	printf("\n----lstadd_back-----\n");
	printf("\n----lstdelone-----\n");
	printf("\n----lstclear-----\n");
	printf("\n----lstiter-----\n");
	printf("\n----lstmap-----\n");
}
