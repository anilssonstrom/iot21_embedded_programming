#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length(char *str)
{
    // Funktion som räknar ut en strängs längd

    // Samma implementering som tidigare idag
    int while_counter = 0;

    char *my_char_pointer;  // Pekare till ett tecken i strängen
    my_char_pointer = str;

    while (*my_char_pointer != '\0')  // *: Är värdet null?
    {
        while_counter++;
        my_char_pointer++;
    }

    return while_counter;
}

void print_int_array(int *arr, int arr_len)
{
    int j = 0;
    int *j_ptr = arr;
    while (j < arr_len)
    {
        printf("0x%p: %d\n", j_ptr, *j_ptr);
        j++;
        j_ptr++;
    }
}

int main()
{
    // Öppna en fil och skriv "Hello World" till filen
    FILE *file_ptr = fopen("out.txt", "w");
    fprintf(file_ptr, "Hello World!\n");
    fclose(file_ptr);

    // Läs från en fil
    char line[255]; // Skapa en buffer för att hålla datan vi läser
    FILE *infile = fopen("indata.txt", "r");  // Öppna filen

    // Gör en av följande:
    fscanf(infile, "%s", line);  // Läs första ordet
    fgets(line, 255, infile);  // Läs första radne
    fread(line, sizeof(char), 255, infile);  // Läs hela filen (eller max 255 tecken), vilket som är mindre

    fclose(infile);  // Stäng filen
    printf("%s\n", line);  // Skriv ut det vi läste

    ///////////////////////////

    // Skicka en vanlig int-array som en pekare till en funktion
    int int_arr[] = {5, 4, 3, 2, 1};
    print_int_array(int_arr, 5);

    // Räkna strängens längd, men som en funktion denna gång
    char my_str[] = "Hello World!";
    int str_len = string_length(my_str);
    printf("%d\n", str_len);

    return 0;
}


// Om funktionerna vi använder ligger efter main() så måste vi deklarera hur de
// ser ut innan vi använder dem. Annars gör kompilatorn dumma antaganden om typer...
void print_int_pointer(int *ptr);
void print_array(int *arr);

void print_a_number()
{
    printf("%d\n", 24);
}

int give_me_a_number()
{
    return 48;
}

void print_this_number(int num)
{
    printf("%d\n", num);
}

const char * get_hello_string()
{
    char *retval = "Hello World!";
    return retval;
}

void print_this_string(const char *str)
{
    printf("%s\n", str);
}

int main2()
{
    // Main omdöpt till main2 för att göra en ny main ovanför.

    // Två sätt att skapa strängar
    char my_str[] = "Hello World!";
    char *my_str_ptr = "Hello World!";

    // Skicka båda två till vår string_length-funktion
    int str_len = string_length(my_str);
    int str_len2 = string_length(my_str_ptr);

    printf("%d\n", str_len);
    printf("%d\n", str_len2);

    // Vad är storleken på våra pekare?
    printf("Sizeof my_str: %d\n", sizeof(str_len));
    printf("Sizeof my_str_ptr: %d\n", sizeof(str_len2));
    // Jämför med storleken på andra typer
    printf("Sizeof double: %d\n", sizeof(double));
    printf("Sizeof char: %d\n", sizeof(char));
    printf("Sizeof int: %d\n", sizeof(int));

    /////////////////////

    // En funktion som returnerar en sträng
    const char *my_str = get_hello_string();
    printf("%s\n", my_str);

    // Skicka en sträng till en annan funktion
    print_this_string(my_str);

    /////////////////////

    // Exempel på funktioner

    print_a_number(); // Funktionsanrop

    int my_num = give_me_a_number(); // En funktion som returnerar ett tal
    printf("%d\n", my_num);

    print_this_number(42); // En funktion som tar in ett värde

    // Funktion som tar en array
    int my_arr[] = {5, 4, 3, 2, 1};
    print_array(my_arr);

    // Funktion som tar en pekare
    int age = 37;
    print_int_pointer(&age);


    /////////////////////

    // Övning: Skriv kod som räknar längden på en sträng


    char myString[] = "This is a string";

    // Med for-loop
    int counter;
    for(counter = 0 ; myString[counter] != '\0' ; counter++);


    // Sidenote: Räkna alla vanliga tecken, ignorerar mellanslag
    for(int i = 0; myString[i] != NULL, i++)
    {
        if (myString[i] != ' ')
        {
            counter++;
        }
    }

    // Med while-loop
    int while_counter = 0;
    char *my_char_pointer;  // Pekare till ett tecken i strängen
    my_char_pointer = myString; // Kopiera pekaren så vi inte ändrar original-strängens pekare

    // Vandra med pekaren tills vi når null-tecknet
    while (*my_char_pointer != '\0')  // *: Är värdet null?
    {
        while_counter++;
        my_char_pointer++;
    }

    printf("Length with for-loop: %d\n", counter);
    printf("Length with while-loop: %d\n", while_counter);

/////////////////////

    // Arrayer kan hålla flera värden
    int values[] = {10, 20, 30, 40, 50};

    // Vi kan göra addition på arrayer för att kolla på senare saker i minnet
    printf("%d\n", *values);
    printf("%d\n", *(values+1));
    printf("%d\n", *(values+2));
    printf("%d\n", *(values+3));
    printf("%d\n", *(values+4));

    // Sidenot: Spara adressen till tredje värdet i arrayen?
    int *value_ptr = (values + 2);
    printf("%p\n", value_ptr);
    printf("%d\n", *value_ptr);

/////////////////////

    // Övning från förra gången. Reversera en sträng? Går att göra med sträng-biblioteket också
    char s[] = "My String";
    printf("%s", strrev(s));

/////////////////////

    // Intro till pekare

    // Skapa en variabel
    int age = 37;

    printf("%d\n", age);  // Skriv ut variabelns värde
    printf("%p\n", &age); // Var i minnet ligger värdet sparat?

    // Skapa en variabel som kan lagra en minnesaddress till ett heltal
    // Kopiera addressen till "age"-variabeln
    int *age_pointer = &age;

    printf("%p\n", age_pointer);  // Age_pointer innehåller en address
    printf("%d\n", *age_pointer); // Skriv ut värdet som addressen pekar på

    float almost_pi = 3.1;
    float *a_pi_pointer = &almost_pi;

    printf("%f\n", almost_pi);
    printf("%p\n", &almost_pi);

    return 0;
}

void print_int_pointer(int *ptr)
{
    printf("0x%p\n", ptr);  // Skriv ut vilken adress talet ligger lagrat på
    printf("%d\n", *ptr);   // Skriv ut talet
}

void print_array(int *arr)
{
    // Skriv ut varje värde i en array (fast längd 5)
    for (int i=0; i<5; i++)
    {
        printf("%d\n", arr[i]);
    }
}
