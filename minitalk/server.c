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
#include"stdio.h"

void print_char(int sig, siginfo_t *info, void *context)
{
    static int bit_counter = 0;
    static unsigned char byte = 0 ; 
    static int c_pid = 0 ; 

    (void)context ;
    if(c_pid != info->si_pid)
    {
        byte = 0 ;
        bit_counter = 0 ;
    }    
    c_pid = info->si_pid ;
    byte = byte << 1 ;
    if(sig == SIGUSR2)
        byte = byte | 1 ;
    bit_counter++; 
    if(bit_counter == 8){
        write(1 , &byte, 1);
        byte = 0 ;
        bit_counter = 0;
    }
}

int main(){
    int pid;
    struct sigaction sa;

    sa. sa_sigaction = &print_char;
    pid = getpid();
    put_nbr(pid);
    write(1 , &"\n", 1);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1);
    return 0;
}

/*
    97 = 64 + 32 +1

    128 64 32 16 8 4 2 1
    0    1  1  0 0 0 0 1
 */