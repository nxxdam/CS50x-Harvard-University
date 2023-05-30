#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("Text: "); //input text
    int count_letters = 0; //To count letters (uppercase & lowercase)
    int count_words = 1; //To count words
    int count_sentences = 0; //To count sentences

    for (int i = 0; i < strlen(s); i++)

        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) // letter
            {
            //printf("%c",s[i]);//print out the text
                count_letters++;
            }
            if (s[i] == ' ')
            {
                count_words++; //words
            }
            else if (s[i]== '.' || s[i]== '!'|| s[i]=='?') //sentence
            {
                count_sentences++;

            }
    //printf("\n%s",s);
    //printf("\nletter:%i word: %i sentence %i ",count_letters,count_words,count_sentences); //to print & identify number of letters
        }
//Coleman-Liau index
float L = ((float)count_letters/ (float)count_words)*100 ;
float S = ((float)count_sentences/ (float)count_words)*100 ;
float index= 0.0588 * L - 0.296 * S - 15.8 ;
int grade = round(index);


 if(grade <16 && grade >=0)
    {
    printf("Grade %i\n", grade); //numbers between 15 to 1
    }
 else if (grade >=16) //to print grade 16+
    {
    printf("Grade 16+\n");
    }
else if (grade <1)
    {   
    printf(" Before Grade 1...\n"); //to print b4 grade 1
    }
}
