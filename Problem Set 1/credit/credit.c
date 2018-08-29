#include<stdio.h>
#include<cs50.h> //Library from CS50

int main(void)
{
    long long int a = get_long_long("Number: "); //To get a long long int, a builtin function from CS50
    long long int b = a; //To restore the value of the original number
    int temp = 0, t, min = 0, count = 0;
    while (a > 0)
    {
        count += 1; //To know the number of digits
        a /= 10;
        if (a < 100 && a > 9) //To know the first two digits from the number
        {
            min = a;
        }
    }
    a = b;
    //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
    while (a > 0)
    {
        t = ((a % 100) / 10) * 2;
        if (t > 9)
        {
            while (t > 0)
            {
                temp += t % 10;
                t /= 10;
            }
        }
        else
        {
            temp += t;
        }
        a /= 100;
    }
    a = b;
    while (a > 0) //Add the sum to the sum of the digits that weren’t multiplied by 2
    {
        t = (a % 10);
        temp += t;
        a /= 100;
    }
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }
    else if (temp % 10 == 0) //If the total’s last digit is 0, the number is valid!
    {
        if (min == 34 || min == 37)
        {
            printf("AMEX\n");
        }
        else if (min > 50 && min < 56)
        {
            printf("MASTERCARD\n");
        }
        else if ((min / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}