#include <stdio.h>
#include <stdlib.h>

int main()
{
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
