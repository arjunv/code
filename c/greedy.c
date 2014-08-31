#include <stdio.h>
#include <math.h>
#include <cs50.h>

// main function
int main(void)
{
    // system("clear");
    printf("\n\tTIME FOR CHANGE!\n");
    
    // reading float value and changing into int after rounding
    float change_f;
    int change;
    int count = 0;
    do
    {
        printf("\nHow much change is owed: ");
        change_f = GetFloat();
    }
    while(change_f < 0);
    change = round(change_f * 100);

    // quarter 25
    while((change - 25) >= 0)
    {
        change -= 25;
        ++count;
    }

    // dime 10
    while((change - 10) >= 0)
    {
        change -= 10;
        ++count;
    }

    // nickel 5
    while((change - 5) >= 0)
    {
        change -= 5;
        ++count;
    }

    // penny 1
    while((change - 1) >= 0)
    {
        change -= 1;
        ++count;
    }
    
    printf("%d\n",count);
}
