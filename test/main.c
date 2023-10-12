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

#include "headers/libasm.h"

void ft_strlen_single_test(const char *str) {
    const unsigned int origin = strlen(str);
    const unsigned int copy = ft_strlen(str);
    
    printf("%s\n", origin == copy ? "OK" : "KO");
}

void ft_strcpy_single_test(char *src) {
    char *origin = (char *) malloc(BUF_SIZE);
    char *copy = (char *) malloc(BUF_SIZE);

    bzero(origin, BUF_SIZE);
    bzero(copy, BUF_SIZE);
    
    strcpy(origin, src);
    ft_strcpy(copy, src);
    
    printf("%s\n", strcmp(origin, copy) == 0 ? "OK" : "KO");
    
    if (origin != NULL) {
        free(origin);
    }
    if (copy != NULL) {
        free(copy);
    }
}

void ft_strcmp_single_test(char *s1, char *s2) {
    const int origin = strcmp(s1, s2);
    const int copy = ft_strcmp(s1, s2);
    
    printf("%s\n", (origin < 0 && copy < 0) || (origin == 0 && copy == 0) || (origin > 0 && copy > 0) ? "OK" : "KO");
}

void ft_write_single_test(int fd, const void *buf, size_t count) {
    errno = 0;
    
    size_t origin = write(fd, buf, count);
    int origin_error = errno;
    
    errno = 0;
    size_t copy = ft_write(fd, buf, count);
    int copy_error = errno;
    
    printf("%s\n", origin == copy && origin_error == copy_error ? "OK" : "KO");
}

void ft_read_single_test(int fd, int count) {
    char *origin_buf = (char *) malloc(BUF_SIZE);
    char *copy_buf = (char *) malloc(BUF_SIZE);
    bzero(origin_buf, BUF_SIZE);
    bzero(copy_buf, BUF_SIZE);


    errno = 0;
    size_t origin = read(fd, fd == 0 && count == 1 ? NULL : origin_buf, count);
    int origin_error = errno;

    errno = 0;
    size_t copy = ft_read(fd, fd == 0 && count == 1 ? NULL : copy_buf, count);
    int copy_error = errno;

    printf("%s\n", origin == copy && origin_error == copy_error && strcmp(origin_buf, copy_buf) == 0 ? "OK" : "KO");

    if (origin_buf != NULL) {
        free(origin_buf);
    }
    if (copy_buf != NULL) {
        free(copy_buf);
    }
}

void ft_strdup_single_test(char *s) {
    char *origin = strdup(s);
    char *copy = ft_strdup(s);

    printf("%s\n", strcmp(origin, copy) == 0 ? "OK" : "KO");

    if (origin != NULL) {
        free(origin);
    }
    if (copy != NULL) {
        free(copy);
    }
}

void ft_strlen_test() {
    puts("---ft_strlen---");
    ft_strlen_single_test("Hello, world!");
    ft_strlen_single_test("Hello\0world!");
    ft_strlen_single_test("");
    ft_strlen_single_test("hblbhcwlhscblb                    jkbakb       jksabckCJKnckjDANCJKNjkdbvajkdsbvjkasjkdvalkjdvnanjkvanjvdkln      vhjkkhejkhegehljnjkcebhjcnjk");
    ft_strlen_single_test("        \t\t\t\t\"    \0  ");
    puts("");
}

void ft_strcpy_test() {
    puts("---ft_strcpy---");
    ft_strcpy_single_test("Hello, world!");
    ft_strcpy_single_test("Hello\0world!");
    ft_strcpy_single_test("");
    ft_strcpy_single_test("hblbhcwlhscblb                    jkbakb       jksabckCJKnckjDANCJKNjkdbvajkdsbvjkasjkdvalkjdvnanjkvanjvdkln      vhjkkhejkhegehljnjkcebhjcnjk");
    ft_strcpy_single_test("        \t\t\t\t\"    \0  ");
    puts("");
}

void ft_strcmp_test() {
    puts("---ft_strcmp---");
    ft_strcmp_single_test("Hello, world!", "Hello, world!");
    ft_strcmp_single_test("Hello\0world!", "");
    ft_strcmp_single_test("", "Hello\0world!");
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

    const int fd = open(PATH_TO_TEST_FILE, O_RDWR);
    ft_write_single_test(fd, "Hello, world!", strlen("Hello, world!"));
    close(fd);
    
    puts("");
}

void ft_read_test() {
    puts("---ft_read---");
    ft_read_single_test(0, 3);
    ft_read_single_test(15, BUF_SIZE);
    ft_read_single_test(0, -5);
    ft_read_single_test(0, 1);

    const int fd = open(PATH_TO_TEST_FILE, O_RDWR);
    ft_read_single_test(fd, strlen("Hello, world!"));
    close(fd);

    puts("");
}

void ft_strdup_test() {
    puts("---ft_strdup---");
    ft_strdup_single_test("Hello, world!");
    ft_strdup_single_test("Hello\0world!");
    ft_strdup_single_test("");
    ft_strdup_single_test("hblbhcwlhscblb                    jkbakb       kjhjklDBjkdhdjkshvjksdhfjkdabvjkafnvjnasfsanvjkdvjkfbvjkdbvjkdbvjksajkvbjkvabfjkajbvkbdvKDjb;KBC");
    ft_strdup_single_test("        \t\t\t\t\"    \0  ");
    puts("");
}

int main() {
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_write_test();
    ft_read_test();
    ft_strdup_test();
    return 0;
}