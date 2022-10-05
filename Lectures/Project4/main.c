#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

// Exempel på en const-global
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
    // Varje gång vi anropar fib() så ska den skriva ut nästa tal i fibonacci-serien.
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
    Övning 1:
    # Skapa en strukt student som har ålder och namn
    # Skapa en lista med 10 studenter
    # Skriv ut studenternas ålder och namn i en tabell
    # Spara datan till en textfil
    */

    //////////////////////////

    // Struktar

    // Skapa två variabler av typen Person (Se globala definitionen högst upp)
    Person p1 = {37, "Andreas"};
    Person p2;
    p2.age = 36;
    p2.name = "Ted";

    // Vi kan komma åt personens namn
    printf("p1.name: %s\n", p1.name);

    // Vi kan skapa listor med personer
    Person somePeople[] = {p1, p2};
    // Och indexera i listan
    printf("somePeople[1].name: %s\n", somePeople[1].name);

    // Vi kan skicka struktar till funktioner
    printPersonName(p1);

    // Exempel på Linked lists:
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

    // Förklaring av typedefs
    typedef int NUMBER;
    NUMBER value = 37;

    // Vi får också några typedefs från stdint.h. Användbara i embedded-programmering.
    uint32_t maxSize = 45;

    ///////////////////////////////

    printf("\n\n");

    // Exempel på typedef av enum där vi sätter siffervärdena själv
    typedef enum {
        OK = 200,
        Forbidden = 403,
        NotFound = 404,
        InternalServerError = 500
    } REQUEST_RESULT;

    REQUEST_RESULT result = NotFound;

    // Result kan utvärderas med namn, och skrivas ut för att få en siffra
    if (result == OK)
    {
        printf("OK! %d\n", result);
    }
    else
    {
        printf("Error! %d\n", result);
    }

    // Enum där vi låter C bestämma deras värden (0, 1, 2, ...)
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

    // Kan vi jämföra veckodagar med bool?
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

    // Pekare börjar med p_...
    // p_ageVar = &ageVar;
/*
    PrintHello();

    printf("Max turns: %d\n", G_MAXTURNS);
    */
    return 0;
}
