//To find the vigenere cipher with a key specified by the user in the command line
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2) //To check if there are only correct number of arguments
    {
        int k = strlen(argv[1]); //To get the length of the key
        int d = 0;
        for (int i = 0; i < k; i++) //To parse through the key
        {
            if (isdigit(argv[1][i]) != 0) //To check is there is any digits in the key
            {
                d++;
            }
            else
            {
                argv[1][i] = (int)tolower(argv[1][i]); //To find the offset to be added to the plain text
            }
        }
        if (d != 0) //If there is a digit present in the key, then exit program with return 1
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        else
        {
            string a = get_string("plaintext: ");
            int slen = strlen(a), l = 0;
            printf("ciphertext: ");
            for (int i = 0; i < slen ; i++)
            {
                if (isalpha(a[i]) != 0) //To only give offset to alphabets
                {
                    if (isupper(a[i])) //If it is capital letter, then it has to be treated in a different way. Notice the number 97 and 162 (= 97 + 65)
                    {
                        printf("%c", 65 + ((a[i] + argv[1][l] - 162) % 26));
                    }
                    else //If it is small letter, it has to be treated in a different way. Notice number 97 and 194 (= 97 + 97)
                    {
                        printf("%c", 97 + ((a[i] + argv[1][l] - 194) % 26));
                    }
                    l++; // l is for parsing through the key
                    if (l == k) //When it reaches the end of key, it needs to start from first
                    {
                        l = 0;
                    }
                }
                else //To print the content in the plaintext as it is, if it is not an alphabet
                {
                    printf("%c", a[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
    else //If there are less or more number of arguments than required.
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
}