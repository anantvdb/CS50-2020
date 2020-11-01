#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // declares all variables
    float dollars;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    // asks for an amount of dollars, checks if negative
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    // variable cents
    int cents = round(dollars * 100);
    
    // counts the amount of quarters
    while (cents >= 25)
    {
        cents -= 25;
        quarters++;
    }
    
    // counts the amount of dimes
    while (cents >= 10)
    {
        cents -= 10;
        dimes++;
    }

    // counts the amount of nickels
    while (cents >= 5)
    {
        cents -= 5;
        nickels++;
    }

    // counts the amount of pennies
    while (cents >= 1)
    {
        cents -= 1;
        pennies++;
    }
    
    // counts the total amount of coins (of any type)
    int cash = quarters + dimes + nickels + pennies;
    
    // prints the total amount of coins
    printf("%i\n", cash);
}