#include <stdio.h>
#include <stdlib.h>

void make_pyramid(int *h);
void get_height(int *p);

int main(void)
{
    int *height = malloc(sizeof(int));
    if (height == NULL)
    {
        return 1;
    }

    get_height(height);

    printf("%d high\n", *height);

    make_pyramid(height);

    free(height);

    return 0;
}

void get_height(int *p)
{
    printf("How tall should the pyramid be? ");
    scanf("%d", p);
    if (*p <= 0)
    {
        get_height(p);
    }
}

void make_pyramid(int *h)
{
    for (int boxlevel = 0; boxlevel < *h; ++boxlevel)
    {
        int spacesneeded = *h - boxlevel;
        for (int k = 0; k < spacesneeded; ++k)
        {
            printf(" ");
        }

        for (int leftboxes = 0; leftboxes <= boxlevel; ++leftboxes)
        {
            printf("#");
        }

        //Middle Gap
        printf("  ");

        for (int rightboxes = 0; rightboxes <= boxlevel; ++rightboxes)
        {
            printf("#");
        }
        printf("\n");
    }
}