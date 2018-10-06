/*
 * =====================================================================================
 *
 *       Filename:  endianess.c
 *
 *    Description:  Find the endianess of the system and convert if necessary
 *
 *        Version:  1.0
 *        Created:  10/05/2018 14:47:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SHANMUGAPRIYA RAVINDRAN
 *
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdbool.h>

union Number{
    int num;
    char n[4];
}number;

bool isLittleEndian(void)
{
    union Number number;

    number.num = 1;

    printf("size of int in this machine is %lu\n",sizeof(int));
    printf("first byte: %d\n",number.n[0]);

    if(number.n[0])
    {
        printf("Little Endian\n");
        return true;
    }
    else
    {
        printf("Big Endian\n");
        return false;
    }

}

int changeEndianness(int num)
{
    int b0,b1,b2,b3;
    int revNum = 0;

    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;

    revNum = b0 | b1 | b2 | b3;

    printf("revNum: %x \n", revNum);

    return revNum;
}

int main(void)
{
    bool endianness;

    endianness = isLittleEndian();

    if(endianness == true)
        printf("Is it little endian: Yes\n");
    else
        printf("Is it little endian: No\n");

    printf("Big endian format of 0x1234 is %x\n", changeEndianness(0x1234));

    return 0;
}
