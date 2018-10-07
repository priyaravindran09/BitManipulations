/*
 * =====================================================================================
 *
 *       Filename:  insertBits.c
 *
 *    Description:  Function to insert m bits in n bits between position j and i
 *
 *        Version:  1.0
 *        Created:  10/07/2018 08:59:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SHANMUGAPRIYA RAVINDRAN
 *
 *
 * =====================================================================================
 */
#include <stdio.h>

#define BITSINABYTE 8


void displayBinary(int num)
{
    int i,max;
    max = sizeof(num)*BITSINABYTE;

    for(i = (max-1); i >= 0; i--)
    {
        printf("%d",((num >> i) & 0x01));
    }
    printf("\n");
}

int main(void)
{
    int n,m,j,i,leftMask,rightMask,mask,res;

    printf("Enter the number n in which m bits to be inserted\nEnter the number m to be inserted\nEnter the position j and i\n");
    scanf("%d %d %d %d",&n,&m,&i,&j);

    leftMask = (~0) << (j+1);
    rightMask = (1 << i) - 1;
    mask = leftMask | rightMask;

    res = (n & mask) | (m << j);

    printf("n = %d\nm = %d\nj = %d\ni = %d\nres = %d\n",n,m,j,i,res);
    displayBinary(n);
    displayBinary(m);
    displayBinary(res);
    return 0;
}

