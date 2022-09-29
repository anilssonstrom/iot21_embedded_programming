#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //char name[8] = {'A', 'n', 'd', 'r', 'e', 'a', 's'};
    char name[] = "Andreas";
    printf("%s\n", name);
    printf("%d\n", strlen(name));

/*
    //int values[] = {1, 2, 3, 4, 5};
    int values[1];

    values[0] = 10;
    values[1] = 11;
    values[2] = 12;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", values[i]);
    }
*/

/*
    // Skapa variabler
    const int SIZE_TABLESPOON = 15;
    const int SIZE_TEASPOON = 5;
    int input, tablespoons, teaspoons, remainder;

    // Be användaren om input
    printf("Enter volume to convert (ml): ");
    scanf("%d", &input);

    // Konvertera till matskedar
    tablespoons = input / SIZE_TABLESPOON;

    // Konvertera till teskedar
    // 37 från början
    // Ta bort 30 ml (2 matskedar)
    // 7cl kvar, gör till teskedar
    //teaspoons = (input - (tablespoons * SIZE_TABLESPOON)) / SIZE_TEASPOON;
    teaspoons = (input % SIZE_TABLESPOON) / SIZE_TEASPOON;

    // Räkna ut resten (kryddmått)
    //remainder = input - (tablespoons * SIZE_TABLESPOON) - (teaspoons * SIZE_TEASPOON);
    remainder = input % SIZE_TEASPOON;

    // Skriv ut allt
    printf("Matskedar : %d\n", tablespoons);
    printf("Teskedar  : %d\n", teaspoons);
    printf("Kryddmått : %d\n", remainder);
*/
/*
    // FizzBuzz

    for (int i=1; i <= 30; i++)
    {
        if (i % 15 == 0)
        {
            printf("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            printf("Fizz");
        }
        else if (i % 5 == 0)
        {
            printf("Buzz");
        }
        else
        {
            printf("%d", i);
        }
        printf("\n");
    }
*/
/*
    // Exempel: Break och continue
    for (int i = 0; i <= 10; i++)
    {
        if (i == 4)
        {
            continue;
        }

        printf("%d\n", i);
    }

    int i = 0;
    while (1) {
        printf("%d\n", i);
        i++;

        if (i == 10)
        {
            break;
        }
    }
*/
/*
    // While-loop: Skriv ut 1-10

    int while_counter = 1;
    while(while_counter <= 10)
    {
        printf("%d\n", while_counter);
        while_counter++;
    }


    // For-loop: Skriv ut 1-10
    //    startvärde      villkor           uppdatera
    for (int counter = 1; counter <= 10 ; counter++)
    {
        printf("%d\n", counter);
    }
*/
/*
    // Exempel på switch-case

    //int a = 5;
    char op = '%';

    switch(op)
    {
    case '+':
        printf("Plus\n");  // Missar vi "break" så körs mer kod
    case '-':
        printf("Minus\n");
        break;
    case '*':
        printf("Gånger\n");
        break;
    case '/':
        printf("Division\n");
        break;
    default:
        printf("Unsupported operand\n");
        break;
    }
*/
/*
    // Sizeof för att kolla storleken på saker
    //int age = 37;

    printf("sizeof int: %zu\n", sizeof(int));
    printf("sizeof int: %zu\n", sizeof(char));
    printf("sizeof int: %zu\n", sizeof(float));
*/

/*
    // Exempel på funktionsanrop i uttrycken med ternary operator
    int result = 10;

    (result == 10) ? printf("Result == 10") : printf("Result != 10");
*/
/*
    // Exempel på ternary operator
    int result;
    int a = 5;
    int b = 10;

    result = a < b ? 100 : 200; // Alla tre får vara uttryck.

    printf("%d\n", result);
*/
/*
    // Exempel på att ordningen av ++ spelar roll
    int a = 2;
    int b;

    b = ++a;

    printf("%d\n%d\n", a, b);
*/
/*
    // 0 är falskt, alla andra värden är sanna
    int a = 0;
    int b = 5;
    int c = -5;

    if (b >= a)
    {
        printf("B > A is True\n");
    }

    if (a && b)
    {
        printf("A && B is True\n");
    }
    if (a || b)
    {
        printf("A || B is True\n");
    }
    if (!a && b)
    {
        printf("!A && B is True\n");
    }
*/


    /*
    // Heltalsdivision
    int a, b;
    float result;
    a = 7;
    b = 4;

    result = ((float) a / (float) b);

    printf("%f", result);
    */
    return 0;
}
