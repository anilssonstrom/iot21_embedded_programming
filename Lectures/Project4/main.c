#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

// Exempel p� en const-global
const int G_MAXTURNS = 10;

// Struct-exempel
typedef struct person {
    int age;
    char *name;
} Person;

void fib()
{
    /*
     0 1 1 2 3 5 8 13 21 34
    */
    // Varje g�ng vi anropar fib() s� ska den skriva ut n�sta tal i fibonacci-serien.
    static uint32_t a = 0;
    static uint32_t b = 1;

    uint32_t next = a + b;
    printf("%" PRIu32 " ", next);

    a = b;
    b = next;
}

void PrintHello()
{
    char helloText[] = "Hello World!";
    printf("%s\n", helloText);
}

void printPersonName(Person p)
{
    // Funktion som tar emot en strukt-typ
    printf("p.name: %s\n", p.name);
}

uint32_t main()
{
    /*
    �vning 1:
    # Skapa en strukt student som har �lder och namn
    # Skapa en lista med 10 studenter
    # Skriv ut studenternas �lder och namn i en tabell
    # Spara datan till en textfil
    */

    //////////////////////////

    // Struktar

    // Skapa tv� variabler av typen Person (Se globala definitionen h�gst upp)
    Person p1 = {37, "Andreas"};
    Person p2;
    p2.age = 36;
    p2.name = "Ted";

    // Vi kan komma �t personens namn
    printf("p1.name: %s\n", p1.name);

    // Vi kan skapa listor med personer
    Person somePeople[] = {p1, p2};
    // Och indexera i listan
    printf("somePeople[1].name: %s\n", somePeople[1].name);

    // Vi kan skicka struktar till funktioner
    printPersonName(p1);

    // Exempel p� Linked lists:
    typedef struct linkedlist {
        int value;
        struct linkedlist * next;
    } LinkedList;

    ///////////////////////////////

    // Print fibonacci series
    printf("Fibonacci: 0 1 ");
    for (uint32_t i = 0; i < 5; i++)
    {
        fib();
    }

    ///////////////////////////////

    // F�rklaring av typedefs
    typedef int NUMBER;
    NUMBER value = 37;

    // Vi f�r ocks� n�gra typedefs fr�n stdint.h. Anv�ndbara i embedded-programmering.
    uint32_t maxSize = 45;

    ///////////////////////////////

    printf("\n\n");

    // Exempel p� typedef av enum d�r vi s�tter sifferv�rdena sj�lv
    typedef enum {
        OK = 200,
        Forbidden = 403,
        NotFound = 404,
        InternalServerError = 500
    } REQUEST_RESULT;

    REQUEST_RESULT result = NotFound;

    // Result kan utv�rderas med namn, och skrivas ut f�r att f� en siffra
    if (result == OK)
    {
        printf("OK! %d\n", result);
    }
    else
    {
        printf("Error! %d\n", result);
    }

    // Enum d�r vi l�ter C best�mma deras v�rden (0, 1, 2, ...)
    typedef enum {
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday
    } WEEKDAY;

    WEEKDAY day = monday;
    printf("Weekday: %d\n", day);

    day++;
    printf("Weekday: %d\n", day);

    // Kan vi j�mf�ra veckodagar med bool?
    printf("%d == %d? ", true, wednesday);
    if (wednesday == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    // PascalCase
    // camelCase
    // snake_case
    // ALL_CAPS

    // Om vi har en variabel age
    // ageVar = 37;

    // Pekare b�rjar med p_...
    // p_ageVar = &ageVar;
/*
    PrintHello();

    printf("Max turns: %d\n", G_MAXTURNS);
    */
    return 0;
}
