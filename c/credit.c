#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// GLOBAL DECLARATIONS
    // int array for credit card number
    int card_a[20];

    // char buffer for storing read value 
    char buf[50];
    
    // length of card number and a flag value
    int card_len, flag, j;

// CHECK FUNCTIONS INITIALIZATION
int card_valid(void);
int check_amex(void);
int check_mc(void);
int check_visa(void);

// INPUT CHECK FUNCTION
int isclean(void)
{
    flag = 0, j = 0;

    // check if entered num greater than max size of ull
    // if ( strtoull(buf, NULL, 0) >= ULLONG_MAX)
    // flag = 1;

    // check if any of the entered value is not numeric
    while(j < (strlen(buf) - 1))
    {
        if (isdigit(buf[j]) == 0)
            flag = 1;
        j++;
    }

    // if entered value is not clean
    if (flag == 1)
        return 1;
    else
        return 0;
}

// COPY NUMBER TO INT ARRAY STARTING FROM 1
void conv_array(void)
{
    j = 1;
    while(j < strlen(buf))
    {
        card_a[j] = buf[j - 1] - '0';
        j++;
    }

}

// MAIN FUNCTION
int main(void)
{
    system("clear");    
    printf("\n\tCREDIT CARD CHECKER\n");

    // READ INPUT TO BUFFER, CHECK AND REPROMPT
    do
    {
        printf("\nEnter Credit Card Number: ");
        fgets(buf, sizeof buf, stdin);
    }
    while(isclean());

    // converts char buffer into ull variable card_n
    // unsigned long long int card_n = strtoull(buf, NULL, 0);
    flag = 0;
    // CONVERT BUFFER TO AN INT ARRAY
    // copy content of buf into int array card_a        
    conv_array();
    // string length stored in card_len
    card_len = strlen(buf) - 1;

    // CHECK IF VALID
    if (card_valid())
    {
        // CHECK CARD TYPE BY CARD NUMBER LENGTH
        switch ( card_len )
        {
            case 13:
                if (!check_visa())
                    flag = 1;
                break;
            case 15:
                if (!check_amex())
                    flag = 1;
                break;
            case 16:
            {
                if (!check_visa() && !check_mc())
                    flag = 1;
                break;
            }
            default:
                flag = 1;
                break;
        }
        
        // IF NOT VISA, AMEX OR MC
        if (flag == 1)
            printf("VALID\n");
    }
    else
        printf("INVALID\n");

    // display card number
    // for(int i = 1; i <= card_len; i++)
    // printf("%d",card_a[i]);
    // printf("\n%llu\n",card_n);
}
// END OF MAIN

// CHECK FUNCTIONS
// Luhn's Algorithm
int card_valid(void)
{
    int i=0, n=0, sum=0;
    // sum of every 2nd digit from 2nd last digit
    for(i = card_len - 1; i > 0; i -= 2)
    {
        if ((n = card_a[i] * 2) > 9)
        {
            n = ((n % 10) + (n / 10));
        }
        sum += n;
    }
    // sum of every 2nd digit from last digit
    for(i = card_len; i > 0; i -= 2 )
        sum += card_a[i];
    
    // if last digit of sum is 0, card is valid
    if (sum % 10 == 0)
        return 1;
    else
    {
        // flag = 1;
        return 0;
    }
}

// check if AMEX
int check_amex(void)
{
    if (card_a[1] == 3 && (card_a[2] == 4 || card_a[2] == 7))
    {
        printf("AMEX\n");
        return 1;
    }
    else
        return 0;
}

// check if MASTERCARD
int check_mc(void)
{
    if (card_a[1] == 5 && (card_a[2] >= 1 || card_a[2] <= 5))
    {
        printf("MASTERCARD\n");
        return 1;
    }
    else
        return 0;
}

// check if VISA
int check_visa(void)
{
    if (card_a[1] == 4)
    {
        printf("VISA\n");
        return 1;
    }
    else
        return 0;
}

