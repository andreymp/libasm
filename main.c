/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:38:41 by jobject           #+#    #+#             */
/*   Updated: 2023/10/11 17:49:06 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void ft_strlen_single_test(const char *str) {
    const unsigned int origin = strlen(str);
    const unsigned int copy = ft_strlen(str);
    
    printf("%s\n", origin == copy ? "OK" : "KO");
}

void ft_strcpy_single_test(char *src) {
    char *origin = malloc(512);
    char *copy = malloc(512);

    bzero(origin, 512);
    bzero(copy, 512);
    
    strcpy(origin, src);
    ft_strcpy(copy, src);
    
    printf("%s\n", strcmp(origin, copy) == 0 ? "OK" : "KO");
    
    free(origin);
    free(copy);
}

void ft_strcmp_single_test(char *s1, char *s2) {
    const int origin = strcmp(s1, s2);
    const int copy = ft_strcmp(s1, s2);
    
    printf("%s\n", origin < 0 && copy < 0 || origin == 0 && copy == 0 || origin > 0 && copy < 0 ? "OK" : "KO");
}

void ft_write_single_test(int fd, const void *buf, size_t count) {
    errno = 0;
    
    size_t origin = write(fd, buf, count);
    int origin_error = errno;
    
    size_t copy = ft_write(fd, buf, count);
    int copy_error = errno;
    
    printf("%s\n", origin == copy && origin_error == copy_error ? "OK" : "KO");
}

void ft_strlen_test() {
    puts("---ft_strlen---");
    ft_strlen_single_test("Hello, world!");
    ft_strlen_single_test("Hello\0world!");
    ft_strlen_single_test("");
    ft_strlen_single_test("hblbhcwlhscblb                    jkbakb       ");
    ft_strlen_single_test("        \t\t\t\t\"    \0  ");
    puts("");
}

void ft_strcpy_test() {
    puts("---ft_strcpy---");
    ft_strcpy_single_test("Hello, world!");
    ft_strcpy_single_test("Hello\0world!");
    ft_strcpy_single_test("");
    ft_strcpy_single_test("hblbhcwlhscblb                    jkbakb       ");
    ft_strcpy_single_test("        \t\t\t\t\"    \0  ");
    puts("");
}

void ft_strcmp_test() {
    puts("---ft_strcmp---");
    ft_strcmp_single_test("Hello, world!", "Hello, world!");
    ft_strcmp_single_test("Hello\0world!", "");
    ft_strcmp_single_test("", "");
    ft_strcmp_single_test("hblbhcwlhscblb                    jkbakb       ", "              ");
    ft_strcmp_single_test("        \t\t\t\t\"    \0  ", "        \t\t\t\t\"    \0  ");
    puts("");
}

void ft_write_test() {
    puts("---ft_write---");
    ft_write_single_test(1, "Hello, world!\n", strlen("Hello, world!\n"));
    ft_write_single_test(15, "Hello, world!", strlen("Hello, world!"));
    ft_write_single_test(1, NULL, 1);
    ft_write_single_test(1, "Hello, world!", -3);

    int fd = open("./util/write_example", O_RDWR);
    ft_write_single_test(fd, "Hello, world!", strlen("Hello, world!"));
    close(fd);
    
    puts("");
}

int main() {
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_write_test();
    return 0;
}