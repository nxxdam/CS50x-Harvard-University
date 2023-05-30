#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar;
    int cents = 0;
    do
    {
       dollar = get_float("Change owed?: \n");
       cents = round(dollar * 100);
    }
    while (cents <= 0);

    int count_25 = (cents / 25);
    int count_10 = (cents % 25) / 10;
    int count_5 = ((cents % 25) % 10) / 5
    int count_1 = (((cents % 25) % 10) % 5) / 1;

    printf("%d\n", count_25 + count_10 + count_5 + count_1);
}
