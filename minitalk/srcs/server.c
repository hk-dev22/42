/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:15:13 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/06 18:39:29 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static t_signal g_sign;

void    add_one(int bit)
{
    (void)bit;
    g_sign.bit_msg += 1 << g_sign.bit_shift;
    g_sign.bit_shift++;
}

void    add_zero(int bit)
{
    (void)bit;
    g_sign.bit_shift++;
}

int main(void)
{
    int pid;

    g_sign.bit_shift = 0;
    g_sign.bit_msg = 0;
    pid = getpid();
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    while (1)
    {
        signal(SIGUSR1, add_one);
        signal(SIGUSR2, add_zero);
        pause();
        if (g_sign.bit_shift == 8)
        {
            ft_putchar_fd(g_sign.bit_msg, 1);
            g_sign.bit_shift = 0;
            g_sign.bit_msg = 0;
        }
    }
}