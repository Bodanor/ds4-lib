#include "ds4.h"

struct joystick_t
{
    int x;
    int y;

};

struct trigger_t
{
    int lower_half_trigger;
    int upper_half_trigger;
};
struct button_t
{
    short is_pressed;
};

struct ds4_t
{
    BUTTON * buttons[15];
    JOYSTICK *Ljoystick;
    JOYSTICK *Rjoystick;
    TRIGGER *trigger[2];
    FILE *fd;
    
};

static void strip_bytes(unsigned char *bytes)
{
    unsigned char *tmp = bytes;
    int i;

    for (i = 0; i < 4; i++)
    {
        tmp[i] = bytes[4+i];
    }
}


DS4 *init_DS4()
{
    DS4 *ds4;
    int i;

    ds4 = (DS4*)malloc(sizeof(DS4));
    if (ds4 == NULL)
        return NULL;
    
    for (i = 0; i < 15; i++)
    {   
        ds4->buttons[i] = (BUTTON*)malloc(sizeof(BUTTON));
        if (ds4->buttons[i] == NULL)
            return NULL;
    }

    ds4->Ljoystick = (JOYSTICK*)malloc(sizeof(JOYSTICK));
    if (ds4->Ljoystick == NULL)
        return NULL;

    ds4->Rjoystick = (JOYSTICK*)malloc(sizeof(JOYSTICK));
    if (ds4->Rjoystick == NULL)
        return NULL;
    
    for (i = 0; i < 2; i++)
    {
        ds4->trigger[i] = (TRIGGER*)malloc(sizeof(TRIGGER));
        if (ds4->trigger[i] == NULL)
            return NULL;
    }

    ds4->fd = fopen("/dev/input/js0", "r");
    if (ds4->fd == NULL)
        return NULL;
    return ds4;
    
}

static void update_left_x_joystick(DS4 *ds4, unsigned char *tmp)
{
    if (tmp[1] == 0)
    {
        ds4->Ljoystick->x = 0;
    }
    else if(tmp[1] < 16)
    {
        ds4->Ljoystick->x = 1;
    }
    else if(tmp[1] < 32)
    {
        ds4->Ljoystick->x = 2;
    }
    else if(tmp[1] < 48)
    {
        ds4->Ljoystick->x = 3;
    }
    else if(tmp[1] < 64)
    {
        ds4->Ljoystick->x = 4;
    }
    else if(tmp[1] < 80)
    {
        ds4->Ljoystick->x = 5;
    }
    else if(tmp[1] < 96)
    {
        ds4->Ljoystick->x = 6;
    }
    else if(tmp[1] < 112)
    {
        ds4->Ljoystick->x = 7;
    }
    else if(tmp[1] < 128)
    {
        ds4->Ljoystick->x = 8;
    }
    else if(tmp[1] < 144)
    {
        ds4->Ljoystick->x = -8;
    }
    else if(tmp[1] < 160)
    {
        ds4->Ljoystick->x = -7;
    }
    else if(tmp[1] < 176)
    {
        ds4->Ljoystick->x = -6;
    }
    else if(tmp[1] < 192)
    {
        ds4->Ljoystick->x = -5;
    }
    else if(tmp[1] < 208)
    {
        ds4->Ljoystick->x = -4;
    }
    else if(tmp[1] < 224)
    {
        ds4->Ljoystick->x = -3;
    }
    else if(tmp[1] < 240)
    {
        ds4->Ljoystick->x = -2;
    }
    else if(tmp[1] < 256)
    {
        ds4->Ljoystick->x = -1;
    }
}

static void update_left_y_joystick(DS4 *ds4, unsigned char *tmp)
{
    if (tmp[1] == 0)
    {
        ds4->Ljoystick->y = 0;
    }
    else if(tmp[1] < 16)
    {
        ds4->Ljoystick->y = -1;
    }
    else if(tmp[1] < 32)
    {
        ds4->Ljoystick->y = -2;
    }
    else if(tmp[1] < 48)
    {
        ds4->Ljoystick->y = -3;
    }
    else if(tmp[1] < 64)
    {
        ds4->Ljoystick->y = -4;
    }
    else if(tmp[1] < 80)
    {
        ds4->Ljoystick->y = -5;
    }
    else if(tmp[1] < 96)
    {
        ds4->Ljoystick->y = -6;
    }
    else if(tmp[1] < 112)
    {
        ds4->Ljoystick->y = -7;
    }
    else if(tmp[1] < 128)
    {
        ds4->Ljoystick->y = -8;
    }
    else if(tmp[1] < 144)
    {
        ds4->Ljoystick->y = 8;
    }
    else if(tmp[1] < 160)
    {
        ds4->Ljoystick->y = 7;
    }
    else if(tmp[1] < 176)
    {
        ds4->Ljoystick->y = 6;
    }
    else if(tmp[1] < 192)
    {
        ds4->Ljoystick->y = 5;
    }
    else if(tmp[1] < 208)
    {
        ds4->Ljoystick->y = 4;
    }
    else if(tmp[1] < 224)
    {
        ds4->Ljoystick->y = 3;
    }
    else if(tmp[1] < 240)
    {
        ds4->Ljoystick->y = 2;
    }
    else if(tmp[1] < 256)
    {
        ds4->Ljoystick->y = 1;
    }
}

static void update_right_x_joystick(DS4 *ds4, unsigned char *tmp)
{
    if (tmp[1] == 0)
    {
        ds4->Rjoystick->x = 0;
    }
    else if(tmp[1] < 16)
    {
        ds4->Rjoystick->x = 1;
    }
    else if(tmp[1] < 32)
    {
        ds4->Rjoystick->x = 2;
    }
    else if(tmp[1] < 48)
    {
        ds4->Rjoystick->x = 3;
    }
    else if(tmp[1] < 64)
    {
        ds4->Rjoystick->x = 4;
    }
    else if(tmp[1] < 80)
    {
        ds4->Rjoystick->x = 5;
    }
    else if(tmp[1] < 96)
    {
        ds4->Rjoystick->x = 6;
    }
    else if(tmp[1] < 112)
    {
        ds4->Rjoystick->x = 7;
    }
    else if(tmp[1] < 128)
    {
        ds4->Rjoystick->x = 8;
    }
    else if(tmp[1] < 144)
    {
        ds4->Rjoystick->x = -8;
    }
    else if(tmp[1] < 160)
    {
        ds4->Rjoystick->x = -7;
    }
    else if(tmp[1] < 176)
    {
        ds4->Rjoystick->x = -6;
    }
    else if(tmp[1] < 192)
    {
        ds4->Rjoystick->x = -5;
    }
    else if(tmp[1] < 208)
    {
        ds4->Rjoystick->x = -4;
    }
    else if(tmp[1] < 224)
    {
        ds4->Rjoystick->x = -3;
    }
    else if(tmp[1] < 240)
    {
        ds4->Rjoystick->x = -2;
    }
    else if(tmp[1] < 256)
    {
        ds4->Rjoystick->x = -1;
    }
}

static void update_right_y_joystick(DS4 *ds4, unsigned char *tmp)
{
    if (tmp[1] == 0)
    {
        ds4->Rjoystick->y = 0;
    }
    else if(tmp[1] < 16)
    {
        ds4->Rjoystick->y = -1;
    }
    else if(tmp[1] < 32)
    {
        ds4->Rjoystick->y = -2;
    }
    else if(tmp[1] < 48)
    {
        ds4->Rjoystick->y = -3;
    }
    else if(tmp[1] < 64)
    {
        ds4->Rjoystick->y = -4;
    }
    else if(tmp[1] < 80)
    {
        ds4->Rjoystick->y = -5;
    }
    else if(tmp[1] < 96)
    {
        ds4->Rjoystick->y = -6;
    }
    else if(tmp[1] < 112)
    {
        ds4->Rjoystick->y = -7;
    }
    else if(tmp[1] < 128)
    {
        ds4->Rjoystick->y = -8;
    }
    else if(tmp[1] < 144)
    {
        ds4->Rjoystick->y = 8;
    }
    else if(tmp[1] < 160)
    {
        ds4->Rjoystick->y = 7;
    }
    else if(tmp[1] < 176)
    {
        ds4->Rjoystick->y = 6;
    }
    else if(tmp[1] < 192)
    {
        ds4->Rjoystick->y = 5;
    }
    else if(tmp[1] < 208)
    {
        ds4->Rjoystick->y = 4;
    }
    else if(tmp[1] < 224)
    {
        ds4->Rjoystick->y = 3;
    }
    else if(tmp[1] < 240)
    {
        ds4->Rjoystick->y = 2;
    }
    else if(tmp[1] < 256)
    {
        ds4->Rjoystick->y = 1;
    }
}

int get_ds4_key(DS4 *ds4)
{
    unsigned char tmp[8];
    fread(&tmp, 8, 1, ds4->fd);
    strip_bytes(tmp);

    if (tmp[3] >= 0 && tmp[3] <6 && tmp[2] == 1)
        ds4->buttons[tmp[3]]->is_pressed = tmp[0];
    
    if (tmp[3] == 6 && tmp[2] == 2 && tmp[1] == 0x80)
        ds4->buttons[6]->is_pressed = 1;
    else
        ds4->buttons[6]->is_pressed = 0;
    
    if (tmp[3] == 6 && tmp[2] == 2 && tmp[1] == 0x7f)
        ds4->buttons[8]->is_pressed = 1;
    else
        ds4->buttons[8]->is_pressed = 0;

    if (tmp[3] == 7 && tmp[2] == 2 && tmp[1] == 0x80)
        ds4->buttons[7]->is_pressed = 1;
    else
        ds4->buttons[7]->is_pressed = 0;
    
    if (tmp[3] == 7 && tmp[2] == 2 && tmp[1] == 0x7f)
        ds4->buttons[9]->is_pressed = 1;
    else
        ds4->buttons[9]->is_pressed = 0;

    if (tmp[3] == 8 && tmp[2] == 1)
        ds4->buttons[10]->is_pressed = tmp[0];

    if (tmp[3] == 9 && tmp[2] == 1)
        ds4->buttons[11]->is_pressed = tmp[0];

    if (tmp[3] == 10 && tmp[2] == 1)
        ds4->buttons[12]->is_pressed = tmp[0];
    
    if (tmp[3] == 11 && tmp[2] == 1)
        ds4->buttons[13]->is_pressed = tmp[0];
    
    if (tmp[3] == 12 && tmp[2] == 1)
        ds4->buttons[14]->is_pressed = tmp[0];

    if (tmp[2] == 2)
    {
        if (tmp[3] == 0)
            update_left_x_joystick(ds4, tmp);
        else if (tmp[3] == 1)
            update_left_y_joystick(ds4, tmp);
        else if (tmp[3] == 3)
            update_right_x_joystick(ds4, tmp);
        else if (tmp[3] == 4)
            update_right_y_joystick(ds4, tmp);
    }


    return 0;

}

void print_ds4_debug_key(DS4 *ds4)
{
    if (ds4->buttons[0]->is_pressed == 1 && ds4->buttons[2])
        printf("Cross button " BGRN "pressed.\n" reset);
    else
        printf("Cross button " BRED "released.\n" reset);
    
    if (ds4->buttons[1]->is_pressed == 1)
        printf("Circle button " BGRN "pressed.\n" reset);
    else
        printf("Circle button " BRED "released.\n" reset);
    
    if (ds4->buttons[2]->is_pressed == 1)
        printf("Triangle button " BGRN "pressed.\n" reset);
    else
        printf("Triangle button " BRED "released.\n" reset);
    
    if (ds4->buttons[3]->is_pressed == 1)
        printf("Square button " BGRN "pressed.\n" reset);
    else
        printf("Square button " BRED "released.\n" reset);
    
    if (ds4->buttons[4]->is_pressed == 1)
        printf("L1 button " BGRN "pressed.\n" reset);
    else
        printf("L1 button " BRED "released.\n" reset);
    
    if (ds4->buttons[5]->is_pressed == 1)
        printf("L2 button " BGRN "pressed.\n" reset);
    else
        printf("L2 button " BRED "released.\n" reset);
    
    if (ds4->buttons[6]->is_pressed == 1)
        printf("Left Arrow button " BGRN "pressed.\n" reset);
    else
        printf("Left Arrow button " BRED "released.\n" reset);
    
    if (ds4->buttons[7]->is_pressed == 1)
        printf("Up Arrow button " BGRN "pressed.\n" reset);
    else
        printf("Up Arrow button " BRED "released.\n" reset);
    
    if (ds4->buttons[8]->is_pressed == 1)
        printf("Right Arrow button " BGRN "pressed.\n" reset);
    else
        printf("Right Arrow button " BRED "released.\n" reset);
    
    if (ds4->buttons[9]->is_pressed == 1)
        printf("Down Arrow button " BGRN "pressed.\n" reset);
    else
        printf("Down Arrow button " BRED "released.\n" reset);
    
    if (ds4->buttons[10]->is_pressed == 1)
        printf("Share button " BGRN "pressed.\n" reset);
    else
        printf("Share button " BRED "released.\n" reset);
    
    if (ds4->buttons[11]->is_pressed == 1)
        printf("Option button " BGRN "pressed.\n" reset);
    else
        printf("Option button " BRED "released.\n" reset);
    
    if (ds4->buttons[12]->is_pressed == 1)
        printf("PS button " BGRN "pressed.\n" reset);
    else
        printf("PS button " BRED "released.\n" reset);
    
    if (ds4->buttons[13]->is_pressed == 1)
        printf("L3 button " BGRN "pressed.\n" reset);
    else
        printf("L3 button " BRED "released.\n" reset);
    
    if (ds4->buttons[14]->is_pressed == 1)
        printf("R3 button " BGRN "pressed.\n" reset);
    else
        printf("R3 button " BRED "released.\n" reset);
    
    printf("Left Joystick X : " BBLU "%d\n" reset, ds4->Ljoystick->x);
    printf("Left Joystick Y : " BBLU "%d\n" reset, ds4->Ljoystick->y);
    printf("Right Joystick X : " BBLU "%d\n" reset, ds4->Rjoystick->x);
    printf("Right Joystick Y : " BBLU "%d\n"reset,  ds4->Rjoystick->y);
    

    putchar('\n');

}