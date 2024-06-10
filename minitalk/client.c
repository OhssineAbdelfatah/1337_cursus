/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:42:29 by aohssine          #+#    #+#             */
/*   Updated: 2024/06/08 13:12:14 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void put_message(char *str, int fd)
{
    while(*str)
        write( fd, str++, 1);
    return ;
}

int convert_char(char *pid, char *msg)
{
    int counter;
    int count_bit;

    counter = 0 ;
    while(msg[counter] != '\0')
    {   
        count_bit = 0;
        while( count_bit < 8){
            if(1 & (msg[counter] >> count_bit))
                kill(ft_atoi(pid), SIGUSR1);
            else
                kill(ft_atoi(pid), SIGUSR2);
            count_bit++;
        } 
        counter++;
    }
    return 0;
}

int main(int ac, char *av[])
{
    if(ac == 3)
        convert_char(av[1], av[2]);
    else 
        put_message("client [server PID] [message]", 1);
    return 0;
}