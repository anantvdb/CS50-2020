#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    // declares variable heighth
    int height;
    
    // repeats if the number isn't a positive integer between 1 and 8
    do
    {
        // asks for the height and stores it in the integer height
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // for loop, each iteration is one line
    for (int j = 1 ; j <= height ; j++)
    {
        
        // prints a space height-j times
        for (int i = 0 ; i < height - j ; i++)
        {
            printf(" ");
        }
        
        // prints a hashtag j times
        for (int i = 0 ; i < j ; i++)
        {
            printf("#");
        }
        
        // print two spaces
        printf("  ");
        
        // prints a hashtag j times
        for (int i = 0 ; i < j ; i++)
        {
            printf("#");
        }
        
        // goes to the next line
        printf("\n");
    }
    
    
}