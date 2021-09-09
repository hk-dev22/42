/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:17:17 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/07 21:44:50 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include "time.h"

void    send_message(int pid, char *msg)
{
    int i;
    int bit_shift;

    i = 0;
    while(msg[i])
    {
        bit_shift = 0;
        while (bit_shift < 8)
        {
            if ((msg[i] >> bit_shift) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            bit_shift++;
            usleep(1000);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int     pid;
    char    *message;
    clock_t ti;
    double  time_taken;

    if (ac != 3)
    {
        ft_putstr_fd("Sorry, wrong number of arguments (3), please try again!", 1);
        return (0);
    }
    ti = clock();
    pid = ft_atoi(av[1]);
    message = av[2];
    send_message(pid, message);
    ti = clock() - ti;
    time_taken = ((double)ti)/CLOCKS_PER_SEC;
    ft_putstr_fd(ft_itoa(time_taken), 1);
}