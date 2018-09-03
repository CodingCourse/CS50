//To find caesar cypher of text
#define _XOPEN_SOURCE
#include <unistd.h>
#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(int argc, string argv[]) //This is for getting command line arguments
{
    int i, j = 1, k, l, m;
    char a[2], c[5], d[54]; //a to store salt, c to store key and d to store all possible characters
    string temp; //temp to store the hash created to compare with the hash provided
    a[0] = argv[1][0];
    a[1] = argv[1][1];
    if (argc == 2) //We need one argument, neither more nor less
    {
        d[0] = '\0';
        for (i = 65; i < 123; i++, j++) //To get all the alphabets
        {
            d[j] = i;
            if (i == 90) //When it reaches 90, i.e. Z, the next alphabet is at 97
            {
                i = 96; //It is assigned 96, because with the i++ from for loop, it will become 97
            }
        }
        for (i = 0; i < 54; i++)
        {
            for (j = 0; j < 54; j++)
            {
                for (k = 0; k < 54; k++)
                {
                    for (l = 0; l < 54; l++)
                    {
                        for (m = 0; m < 54; m++)
                        {
                            c[0] = d[m];
                            c[1] = d[l];
                            c[2] = d[k];
                            c[3] = d[j];
                            c[4] = d[i];
                            temp = crypt(c, a); //Finding the hash with the current key and salt
                            if (strcmp(argv[1], temp) == 0) //Checking is the hash matches
                            {
                                printf("%s\n", c);
                                return 0;
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Usage: %s hash\n", argv[0]); //If correct number of arguments are not added
        return 1;
        exit(1);
    }
    printf("Usage: %s hash\n", argv[0]); //If hash is not found
    return 1;
}