#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = 0;

    while (size > 8 || size <= 0)
    {
        size = get_int("enter size: ");
    }

    for (int i = 0; i < size; i++)
    {
        if (i != 0)
        {
            printf("\n");
        }
        for (int j = size - 1; j >= 0; j--)
        {
            if (j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
    }
    printf("\n");
}