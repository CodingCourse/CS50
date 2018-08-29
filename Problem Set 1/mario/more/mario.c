//To create a mario like tree
#include<stdio.h>
#include<cs50.h>
int value();
int main(void)
{
    int a = value();
    for (int i = 1; i <= a; i++)
    {
        for (int k = 0; k < a - i; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
//This function is to retry for input
//values until we get an apt one.
int value()
{
    int a = get_int("Height: ");
//To check negative numbers
    if (a < 0)
    {
        a = value();
    }
//To check numbers greater than 23
    if (a > 23)
    {
        a = value();
    }
    return a;
}