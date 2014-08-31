/*******************************************************
 *
 * File              cript.c
 * Date              19/05/2014
 * Author            Arjun V, arjunv[@]live.in
 * Requires          User must pass encrypted password as argument
 * Description       Program to decrypt a DES encrypted password
 *
 *****************************************************/
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

#define _XOPEN_SOURCE

int check(int);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    int p_len = strlen(argv[1]);
    char password[p_len];

    for (int i = 0; i < p_len; i++)
    {
        password[i] = argv[1][i];
    }

    char salt[2];
    while(1)
    {
        for(int i=46; i<123; ++i)
        {
            for(int j=46; j<123; ++j)
            {
                salt[0] = (char)i;
                salt[1] = (char)j;
                
                FILE *fp;
                fp = fopen("/usr/share/dict/words", "r");
                char line[50];

                while(fgets(line, 9, fp)!= NULL)
                {
                    // printf("%s\n",line);
                    line[strlen(line) - 1] = '\0';            
                    if (!strcmp(argv[1], crypt(line, salt)))
                    {
                        printf("%s\n",line);
                        return 0;
                    }
                    printf(".");
                }
                fclose(fp);
                j = check(j);
                printf("-");
            }
            i = check(i);
            printf("~");
        }
    }
    printf("Not found\n");
    return 0;
}

int check(int x)
{
    if(x == 57)
        return 65;
        
    else if(x == 90)
        return 97;
        
    else
        return x;
}

