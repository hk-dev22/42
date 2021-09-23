/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:08:51 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/18 20:14:25 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#

int main(int ac, char **av)
{
    int fd;
    char *line;
    int count_line;
    int result;
    (void)ac;

    fd = open(av[1], O_RDONLY);
    while ((result = get_next_line(fd, &line)) > 0)
    {
        printf("Line: %s", line);
        count_line++;
    }
}