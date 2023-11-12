#include <stdio.h>
#include <stdlib.h>

void make_pyramid(int *h);

int main(void)
{
    int *height = malloc(sizeof(int));
    if (height == NULL)
    {
        return 1;
    }

    printf("How tall should the pyramid be? ");
    scanf("%i", height);
    printf("%d high\n", *height);

    make_pyramid(height);

    free(height);

    return 0;
}

void make_pyramid(int *h)
{
    for (int i = 0; i < *h; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            printf("#");
        }
        printf("\n");
    }
}