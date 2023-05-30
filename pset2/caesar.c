#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool checkint(string text);
int stringToInt(string text);
bool uppercase(char character);
bool lowercase(char character);

int main(int argc, string argv[])
{ if (argc != 2 || !checkint(argv[1]))            //correct argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string plain =get_string("plaintext: ");           //take string from user

        int key = stringToInt(argv[1]) % 26;                // stringToInt function to get key
        int charint = 0;  ///to loop in shifting & printing characters 1 by 1
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain); i++)
        {
            if (uppercase(plain[i]) || lowercase(plain[i]))     //lowercase & uppercase 
            {
                charint = plain[i] + key;
                if ((charint > 90 && uppercase(plain[i])) || (charint > 122 && lowercase(plain[i])))
                {
                    charint -= 26;
                }
                printf("%c", charint);
            }
            else
            {
                printf("%c", plain[i]);
            }
        }
        printf("\n");
    }
} bool checkint(string text) //command-line arguement is an int
{
    bool integer = true;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] < 48 || text[i] > 57)
        {
            integer = false;
        }
    }
    return integer;
}
int stringToInt(string text)    //string to int
{
    int num [10];
    int digit = 0;
    int b;
    for (int k = 0; text[k] != '\0'; k++)
    {
        b = k;
    }
    for (int i = 0; i <= b; i++)
    {
        num [i] = text[i];
        if (num[i] >= 48 && num[i] <= 57)
        {
            num[i] = num[i] - 48;
            for (int j = b - i; j > 0; j--)
            {
                num[i] *= 10;
            }
            digit += num[i];
        }
    }
    return digit;
}
bool lowercase(char character)
{
    if (character <= 122 && character >= 97)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool uppercase(char character)
{
    if (character <= 90 && character >= 65)
    {
        return true;
    }
    else
    {
        return false;
    }
}
