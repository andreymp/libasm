/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobject <jobject@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:38:41 by jobject           #+#    #+#             */
/*   Updated: 2023/10/10 17:30:56 by jobject          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void ft_strlen_test(const char *str) {
    unsigned int origin = strlen(str);
    unsigned int copy = ft_strlen(str);
    
    printf("str :: {%s}, origin :: %d, copy :: %d, equality :: %s", str, origin, copy, origin == copy ? "OK" : "KO");
}

int main() {
    puts("---ft_strlen---");
    ft_strlen_test("Hello, world!");

    return 0;
}