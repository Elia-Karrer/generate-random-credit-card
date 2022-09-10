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


// Returns random card number as string
char* new_card(void)
{
    char* output;
    uint8_t i, t, checksum;
    uint8_t sum_1, sum_2, count_4;

    
    srand(time(NULL));
    
    // Allocate memory for output string
    output = (char*) malloc((16 + 1) * sizeof(char));
    if(output == NULL)
        return NULL;
    
    // Process even indexes
    sum_1 = 0;
    count_4 = 0;
    for(i = 0; i < 8; i++)
    {
        // Generate random digit
        t = rand() % 10;

        // Add to sum of even indexes
        sum_1 += t;

        // Add to count of even indexes greater than 4
        if(t > 4)
            count_4++;
        
        // Store digit in string
        output[i*2] = '0' + t;
    }

    // Process odd indexes (1 less, because checksum digit is not random)
    sum_2 = 0;
    for(i = 0; i < 7; i++)
    {
        // Generate random digit
        t = rand() % 10;

        // Add to sum of odd indexes
        sum_2 += t;
        
        // Store digit in string
        output[i*2+1] = '0' + t;
    }
    
    // Checksum = sum of sums and counts
    checksum = sum_1*2 + sum_2 + count_4;
    
    // Shorten checksum to the digit, missing to next multiple of 10
    checksum = (checksum % 10) ? 10 - (checksum % 10) : 0;
    
    // Store checksum in string
    output[15] = '0' + checksum;

    // Terminate string
    output[16] = '\0';
    
    return output;
}


// Prints card in format of "xxxx xxxx xxxx xxxx"
void print_card(char* card)
{
    uint8_t i, j;

    // Loop through groups of 4 digits
    for(i = 0; i < 4; i++)
    {
        // Print current group of 4 digits
        for(j = 0; j < 4; j++)
            putchar(card[i*4+j]);

        putchar(' ');
    }
}


// Test code
int main(void)
{
    char* card;

    card = new_card();
    print_card(card);

    free(card);
    return 0;
}

