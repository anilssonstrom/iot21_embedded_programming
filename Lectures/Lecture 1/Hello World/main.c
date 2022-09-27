#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    // Skriv ut max och min av några typer
    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("The maximum value of INT = %d\n", INT_MAX);

    printf("The maximum value of UINT = %u\n", UINT_MAX);


    // Be användaren mata in ett tal. Skriva ut talet.
    int inputValue;
    printf("Enter an integer: ");
    scanf("%d", &inputValue);
    printf("The number is %d", inputValue);


    // Övning: Räkna ut arean av en rektangel

    int side_a, side_b, area;
    printf("Enter side a: ");
    scanf("%d", &side_a);
    printf("Enter side b: ");
    scanf("%d", &side_b);

    area = side_a * side_b;

    printf("The area is %d\n", area);

    // Ex: Runda ett float-tal

    float myFloat = 2.235561;

    printf("Float: %.2f", myFloat);

    return 0;
}
