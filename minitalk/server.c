/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:42:26 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/08 13:13:15 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void handel_signal(int sig)
{
    (void)sig;
    write(1 , &"0\n", 1);
}

int main(){
    int pid;

    struct sigaction sa;

    sa.sa_handler = &handel_signal;
    pid = getpid();
    put_nbr(pid);
    write(1 , &"\n", 1);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    return 0;
}