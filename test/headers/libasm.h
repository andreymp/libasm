/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:38:36 by jobject           #+#    #+#             */
/*   Updated: 2023/10/11 17:25:36 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASH_H
# define LIBASH_H

# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define BUF_SIZE 512
# define PATH_TO_TEST_FILE "./util/test_util"

size_t ft_strlen(const char *c);
char *ft_strcpy(char *restrict dst, const char *restrict src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, const void *buf, size_t count);
char *ft_strdup(const char *s);

#endif