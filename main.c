#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "ds4.h"


int main()
{
    FILE *file_dst = fopen("/dev/input/js0", "r");
    DS4 *ds4;
    if (file_dst == NULL)
    {
        printf("Could not read input from controller\nReason : %s\n", strerror(errno));
        return -1;
    }

    ds4 = init_DS4();
    if (ds4 == NULL)
        return -1;

    while (1)
    {
        get_ds4_key(ds4);
        print_ds4_debug_key(ds4);
    }

}