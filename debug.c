#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "ds4.h"



int main()
{
    FILE *file_dst = fopen("/dev/input/js0", "r");
    int i = 0;
    char tmp[8];
    if (file_dst == NULL)
    {
        printf("Could not read input from controller\nReason : %s\n", strerror(errno));
        return -1;
    }


    while (1)
    {
        fread(&tmp, 8, 1, file_dst);

        for (i = 0; i < 8; i ++)
        {
            printf("%d\n", tmp[i]);
        }

        printf("\n");

    }

}