//To find caesar cypher of text
#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(int argc, string argv[]) //This is for getting command line arguments
{
    if (argc == 2) //To check if there are only correct number of arguments
    {
        string a = get_string("plaintext: ");
        int slen = strlen(a);
        printf("ciphertext: ");
        for (int i = 0; i < slen; i++) //To parse through the entire string
        {
            int c = (int)a[i] + atoi(argv[1]); //Sum of the ASCII value of the char and the offset received through command line
            if ((int)a[i] >= 65 && (int)a[i] <= 90) //To check if it is between A to Z
            {
                if (c > 90) //If the offset results the value to be out of A to Z, then move back to A
                {
                    c = 65 + ((c - 91) % 26);
                }
                printf("%c", c);
            }
            else if ((int)a[i] >= 97 && (int)a[i] <= 122) //To check if it is between a to z
            {
                if (c > 122) //If the offset results the value to be out of a to z, then move back to a
                {
                    c = 97 + ((c - 123) % 26);
                }
                printf("%c", c);
            }
            else
            {
                printf("%c", a[i]); //If any other character, then print directly.
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: %s k\n", argv[0]); //If correct number of arguments are not added
        return 1;
    }
}