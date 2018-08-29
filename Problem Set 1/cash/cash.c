#include<stdio.h>
#include<cs50.h>
#include<math.h>

float value();

int main(void)
{
    int a = round(value() * 100);
    int total = 0;
    total = a / 25;
    a = a % 25;
    total += a / 10;
    a = a % 10;
    total += a / 5;
    a = a % 5;
    total += a / 1;
    printf("%i\n", total);
}
//This function is to retry for input
//values until we get an apt one.
float value()
{
    float a = get_float("Change owed: ");
//To check negative numbers
    if (a < 0)
    {
        a = value();
    }
    return a;
}