#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // gets a string of text from the user
    string text = get_string("Text: ");

    // calculates and outputs the number of letters
    int letters = count_letters(text);
    // printf("%i letter(s)\n", letters);

    // calculates and outputs the number of words
    int words = count_words(text);
    // printf("%i word(s)\n", words);

    // calculates and outputs the number of sentences
    int sentences = count_sentences(text);
    // printf("%i sentence(s)\n", sentences);

    // calculates index
    float index = 5.88 * letters / words - 29.6 * sentences / words - 15.8;

    // output
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    // variable for counting letters
    int letters = 0;

    // calculates amount of letters
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // returns amount of letters
    return letters;
}

int count_words(string text)
{
    // variable for counting words
    int words = 1;

    // calculates amount of words
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    // returns amount of words
    return words;
}

int count_sentences(string text)
{
    // variable for counting sentences
    int sentences = 0;

    // calculates amount of sentences
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        if (text[i] == '.' | text[i] == '!' | text[i] == '?')
        {
            sentences++;
        }
    }

    // returns amount of words
    return sentences;
}