#include <cs50.h>
#include <stdio.h>

// main function
int main(void)
{
    // asks for a name
    string name = get_string("What is your name? ");

    // prints hello, so-and-so, where so-and-so is replaced by the name
    printf("hello, %s\n", name);
}
