/*
    Author: Elia Karrer
    Date: 09-10-2022

    DISCLAIMER:
    I am not responsible for any damage, which is done, using this code.

    LICENSE: MIT
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>
#include <time.h>


char* random_card(void)
{
    char* output;
    uint8_t i, t, checksum;
    uint8_t digits[15];
    uint8_t sum_1, sum_2, count_4;
    
    
    srand(time(NULL));
    
    output = (char*) malloc((16 + 1) * sizeof(char));
    if(output == NULL)
        return NULL;
    
    sum_1 = 0;
    count_4 = 0;
    for(i = 0; i < 8; i++)
    {
        t = rand() % 10;
        sum_1 += t;
        if(t > 4)
            count_4++;
            
        digits[i*2] = t;
        output[i*2] = '0' + t;
    }
    
    sum_2 = 0;
    for(i = 0; i < 7; i++)
    {
        t = rand() % 10;
        sum_2 += t;
        
        digits[i*2+1] = t;
        output[i*2+1] = '0' + t;
    }
    
    checksum = sum_1*2 + sum_2 + count_4;
    
    if(checksum % 10)
        checksum = 10 - (checksum % 10);
    else
        checksum = 0;
        
    output[15] = '0' + checksum;
    output[16] = '\0';
    
    return output;
}


int main(void)
{
    puts(random_card());
}


