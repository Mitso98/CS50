// this program takes a key and then substitute plain text with the key
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check whether the user entered only two arguments
    if (argc != 2)
    {
        return 1;
    }
    // check length
    else if (argv[1][26] != '\0')
    {
        printf("you must enter 26 charcter\n");
        return 1;
    }
    // check whether input is only alpha
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("you must only enter charcters\n");
            return 1;
        }
        else
        {
            // check whether there are duplicates
            int check = 0;
            for (int j = 0; j < 26; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    check++;
                    if (check > 1)
                    {
                        printf("you can not enter duplicates!");
                        return 1;
                    }
                }
            }
        }
    }
    // get the plain text
    string word = get_string("plaintext: \n");
    // incremental number
    int n = 0;
    while (word[n] != '\0')
    {
        if (isalpha(word[n]))
        {
            // get ascii number of the charcter
            int ascii = (int) word[n];
            if (isupper(word[n]))
            {
                // if the charcter is in upper case we substract 65 and store it at ascii then use it as
                // index to grab the charcter from argv
                // example if word = A then 65 - 65 = 0 so we get argv[0] 
                ascii -= 65;
                word[n] = toupper(argv[1][ascii]);
            }
            else
            {
                ascii -= 97;
                word[n] = tolower(argv[1][ascii]);
            }
        }
        n++;
    }
    // final output
    printf("ciphertext: %s\n", word);
}