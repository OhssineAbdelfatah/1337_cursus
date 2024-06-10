#include"minitalk.h"

void put_nbr(int nbr)
{
    char digits[12];
    int counter;

    counter = -1;
    if(nbr == 0)
        write(1 ,&"0", 1);
    while(nbr){
        digits[++counter] = nbr % 10 + 48 ;
        nbr = nbr / 10 ;
    }
    digits[++counter] = '\0';
    while(counter > -1)
        write(1 ,&digits[counter--], 1);
    return ;
}

