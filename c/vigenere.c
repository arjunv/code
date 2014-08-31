/*******************************************************
 *
 * File              vigenere.c
 * Date              19/05/2014
 * Author            Arjun V, arjunv[@]live.in
 * Requires          User must pass a string 'key' as argument
 * Description       Program to implement Vigenère Cipher
 *
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// ASCII values of 'A' and 'a'
#define ASCII_U 65
#define ASCII_L 97

// alphabet size
#define ALPHA 26

int not_alpha(string);
void cipher(char, int, int);

int main(int argc, string argv[])
{
    // check if only 1 argument, key, is passed and key is an alphabet
    if (argc != 2 || (argc == 2 && not_alpha(argv[1])))
    {
        printf("Usage: %s <alphabetic key>\n",argv[0]);
        return 1;
    }

    // parse key into ascii with base 0
    string key = argv[1];
    int key_len = strlen(key);
    for(int i=0; i < key_len; i++)
    {
        key[i] = tolower(key[i]) - ASCII_L;
    }

    // get plain text
    string text = GetString();

    // call function 'vigenere' for each character in plain text
    for(int i = 0, j = 0, len = strlen(text); i < len; i++)
    {

        // non alphabetic characters are printed as such
        if (!isalpha(text[i]))
        {
            printf("%c",text[i]);
        }
        
        else
        {
            // loop through the key
            j %= key_len;
            
            // if uppercase, call function with flag '0'
            if (isupper(text[i]))
            {
                cipher(text[i], key[j], 0);
            }

            // if lowercase, call function with flag '1'
            else
            {
                cipher(text[i], key[j], 1);
            }
            
            j++;
        }
    }
    printf("\n");
}

/*
 * Function to check if the key is alphabetical
 *
 * Returns '1' if any of the characters is not an alphabet
 *
 */
int not_alpha(string key)
{
    int flag = 0;
    for(int i=0, n=strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            flag = 1;
        }
    }
    return flag;
}


/* Cipher function
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
