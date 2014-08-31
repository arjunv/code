/*******************************************************
 *
 * File              caesar.c
 * Date              19/05/2014
 * Author            Arjun V, arjunv[@]live.in
 * Requires          User must pass a 'key' as argument
 * Description       Program to implement Caesar Cipher
 *
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// ASCII values of 'A' and 'a' taken as base
#define ASCII_U 65
#define ASCII_L 97

// alphabet size
#define ALPHA 26

void cipher(char, int, int);

int main(int argc, string argv[])
{
    // check if only 1 argument, key, is passed
    if (argc != 2 || atoi(argv[1] < 0))
    {
        printf("Usage: %s <key>\n",argv[0]);
        return 1;
    }

    // get key adjusted for alphabet size and plain text
    string text = GetString();

    // call function 'cipher' for each character in plain text
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        // if uppercase, call function with flag '0'
        if (isupper(text[i]))
        {
            cipher(text[i], key, 0);
        }

        // if lowercase, call function with flag '1'
        else if (islower(text[i]))
        {
            cipher(text[i], key, 1);
        }

        // non alphabetic characters are printed as such
        else
        {
            printf("%c",text[i]);
        }
    }

    printf("\n");
}

/*
 * Caesar Cipher function
 *
 * It subtracts from the ASCII value of plain character,
 * the base ASCII value of that case to make it zero index.
 * After enciphering, this base value is added to get
 * the corresponding ASCII value of the cipher text.
 *
 */
void cipher(char plain, int key, int flag)
{
    int ciph;

    // uppercase character
    if (flag == 0)
    {
        ciph = ((plain - ASCII_U) + key) % ALPHA;
        ciph += ASCII_U;
    }

    // lowercase character
    else
    {
        ciph = ((plain - ASCII_L) + key) % ALPHA;
        ciph += ASCII_L;
    }

    // display the enciphered character
    printf("%c",ciph);
}
