#include <stdio.h>
#include <cs50.h>

// draws each line
void drawstep(int, int);

// main function
int main(void)
{
    // system("clear");
    printf("\n\tMARIO'S HALF-PYRAMID\n");
    
    int stepc;
    do
    {
        printf("\nEnter the Height of the Pyramid: ");
        stepc = GetInt();
    }
    while(stepc < 0 || stepc > 23);
    
    // system("clear");
    // printf("\tMARIO'S \"%d\" STEP HALF-PYRAMID\n",stepc); //designer code

    
    for(int i = stepc; i > 0; i--)
    {    
        drawstep(stepc, i);
        printf("\n");
    }
    
}

// Draws each line
void drawstep(int row, int n)
{
    int j;
    for(j = n;j > 1;--j)
    {
        printf(" ");
    }

    
    for(j = (row - n) + 2;j > 0;--j)
    {
        printf("#");
    }
    // show step number   
    // if(row-n+1!=0) printf(" %d",n);
    
}
