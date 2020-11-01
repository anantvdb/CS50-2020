#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

string encipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // returns 1 from main is there are more than or less than 1 arguments
    if (argc != 2)
    {
        printf("Usage: ./encipher key\n");
        return 1;
    }

    // checks that the key is 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // checks for non-alphabetic characters, or for multiple identical characters
    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        else
        {
            for (int j = 0 ; j < i ; j++)
            {
                if (tolower(argv[1][i]) == tolower(argv[1][j]))
                {
                    printf("Key should contain each alphabetic character exactly once.\n");
                    return 1;
                }
            }
        }
    }

    // asks for plaintext
    string plaintext = get_string("plaintext:  ");

    // calculates ciphertext
    string ciphertext = encipher(plaintext, argv[1]);

    // outputs ciphertext and returns 0
    printf("ciphertext: %s\n", ciphertext);
    return 0;

}

string encipher(string plaintext, string key)
{
    // converts key to uppercase
    for (int i = 0 ; i < strlen(key) ; i++)
    {
        key[i] = toupper(key[i]);
    }

    // creates empty string for ciphertext output
    string ciphertext = plaintext;

    // calculates ciphertext using encipher
    for (int i = 0 ; i < strlen(plaintext) ; i++)
    {
        // only changes alphabetic characters
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = key[plaintext[i] - 65];
            }
            else if (islower(plaintext[i]))
            {
                ciphertext[i] = key[plaintext[i] - 97] + 32;
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // returns ciphertext
    return ciphertext;
}
