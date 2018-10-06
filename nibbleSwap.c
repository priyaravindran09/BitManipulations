/*
 * =====================================================================================
 *
 *       Filename:  nibbleSwap.c
 *
 *    Description:  Swap nibbles for 64 bit nuber
 *
 *        Version:  1.0
 *        Created:  10/04/2018 21:34:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SHANMUGAPRIYA RAVINDRAN
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdint.h>

uint8_t swapNibble(uint8_t n)
{
    return (((n >> 4) & 0x0F) |((n << 4) & 0xF0));
}


int main(void)
{
    uint64_t num = 0x1234567812345678;
    int i = 0;
    uint64_t swappedNum = 0;
    uint8_t swappedByte = 0;

    for(i=0; i<=56; i+=8)
    {
       swappedByte = swapNibble((num>>i)&(0xFF));
       swappedNum |= ((uint64_t) swappedByte) << i;
    }

    printf("Given number: %llx\n",num);
    printf("Swapped number: %llx\n",swappedNum);
}
