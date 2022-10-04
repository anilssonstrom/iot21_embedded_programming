#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length(char *str)
{
    // Funktion som r�knar ut en str�ngs l�ngd

    // Samma implementering som tidigare idag
    int while_counter = 0;

    char *my_char_pointer;  // Pekare till ett tecken i str�ngen
    my_char_pointer = str;

    while (*my_char_pointer != '\0')  // *: �r v�rdet null?
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
    // �ppna en fil och skriv "Hello World" till filen
    FILE *file_ptr = fopen("out.txt", "w");
    fprintf(file_ptr, "Hello World!\n");
    fclose(file_ptr);

    // L�s fr�n en fil
    char line[255]; // Skapa en buffer f�r att h�lla datan vi l�ser
    FILE *infile = fopen("indata.txt", "r");  // �ppna filen

    // G�r en av f�ljande:
    fscanf(infile, "%s", line);  // L�s f�rsta ordet
    fgets(line, 255, infile);  // L�s f�rsta radne
    fread(line, sizeof(char), 255, infile);  // L�s hela filen (eller max 255 tecken), vilket som �r mindre

    fclose(infile);  // St�ng filen
    printf("%s\n", line);  // Skriv ut det vi l�ste

    ///////////////////////////

    // Skicka en vanlig int-array som en pekare till en funktion
    int int_arr[] = {5, 4, 3, 2, 1};
    print_int_array(int_arr, 5);

    // R�kna str�ngens l�ngd, men som en funktion denna g�ng
    char my_str[] = "Hello World!";
    int str_len = string_length(my_str);
    printf("%d\n", str_len);

    return 0;
}


// Om funktionerna vi anv�nder ligger efter main() s� m�ste vi deklarera hur de
// ser ut innan vi anv�nder dem. Annars g�r kompilatorn dumma antaganden om typer...
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
    // Main omd�pt till main2 f�r att g�ra en ny main ovanf�r.

    // Tv� s�tt att skapa str�ngar
    char my_str[] = "Hello World!";
    char *my_str_ptr = "Hello World!";

    // Skicka b�da tv� till v�r string_length-funktion
    int str_len = string_length(my_str);
    int str_len2 = string_length(my_str_ptr);

    printf("%d\n", str_len);
    printf("%d\n", str_len2);

    // Vad �r storleken p� v�ra pekare?
    printf("Sizeof my_str: %d\n", sizeof(str_len));
    printf("Sizeof my_str_ptr: %d\n", sizeof(str_len2));
    // J�mf�r med storleken p� andra typer
    printf("Sizeof double: %d\n", sizeof(double));
    printf("Sizeof char: %d\n", sizeof(char));
    printf("Sizeof int: %d\n", sizeof(int));

    /////////////////////

    // En funktion som returnerar en str�ng
    const char *my_str = get_hello_string();
    printf("%s\n", my_str);

    // Skicka en str�ng till en annan funktion
    print_this_string(my_str);

    /////////////////////

    // Exempel p� funktioner

    print_a_number(); // Funktionsanrop

    int my_num = give_me_a_number(); // En funktion som returnerar ett tal
    printf("%d\n", my_num);

    print_this_number(42); // En funktion som tar in ett v�rde

    // Funktion som tar en array
    int my_arr[] = {5, 4, 3, 2, 1};
    print_array(my_arr);

    // Funktion som tar en pekare
    int age = 37;
    print_int_pointer(&age);


    /////////////////////

    // �vning: Skriv kod som r�knar l�ngden p� en str�ng


    char myString[] = "This is a string";

    // Med for-loop
    int counter;
    for(counter = 0 ; myString[counter] != '\0' ; counter++);


    // Sidenote: R�kna alla vanliga tecken, ignorerar mellanslag
    for(int i = 0; myString[i] != NULL, i++)
    {
        if (myString[i] != ' ')
        {
            counter++;
        }
    }

    // Med while-loop
    int while_counter = 0;
    char *my_char_pointer;  // Pekare till ett tecken i str�ngen
    my_char_pointer = myString; // Kopiera pekaren s� vi inte �ndrar original-str�ngens pekare

    // Vandra med pekaren tills vi n�r null-tecknet
    while (*my_char_pointer != '\0')  // *: �r v�rdet null?
    {
        while_counter++;
        my_char_pointer++;
    }

    printf("Length with for-loop: %d\n", counter);
    printf("Length with while-loop: %d\n", while_counter);

/////////////////////

    // Arrayer kan h�lla flera v�rden
    int values[] = {10, 20, 30, 40, 50};

    // Vi kan g�ra addition p� arrayer f�r att kolla p� senare saker i minnet
    printf("%d\n", *values);
    printf("%d\n", *(values+1));
    printf("%d\n", *(values+2));
    printf("%d\n", *(values+3));
    printf("%d\n", *(values+4));

    // Sidenot: Spara adressen till tredje v�rdet i arrayen?
    int *value_ptr = (values + 2);
    printf("%p\n", value_ptr);
    printf("%d\n", *value_ptr);

/////////////////////

    // �vning fr�n f�rra g�ngen. Reversera en str�ng? G�r att g�ra med str�ng-biblioteket ocks�
    char s[] = "My String";
    printf("%s", strrev(s));

/////////////////////

    // Intro till pekare

    // Skapa en variabel
    int age = 37;

    printf("%d\n", age);  // Skriv ut variabelns v�rde
    printf("%p\n", &age); // Var i minnet ligger v�rdet sparat?

    // Skapa en variabel som kan lagra en minnesaddress till ett heltal
    // Kopiera addressen till "age"-variabeln
    int *age_pointer = &age;

    printf("%p\n", age_pointer);  // Age_pointer inneh�ller en address
    printf("%d\n", *age_pointer); // Skriv ut v�rdet som addressen pekar p�

    float almost_pi = 3.1;
    float *a_pi_pointer = &almost_pi;

    printf("%f\n", almost_pi);
    printf("%p\n", &almost_pi);

    return 0;
}

void print_int_pointer(int *ptr)
{
    printf("0x%p\n", ptr);  // Skriv ut vilken adress talet ligger lagrat p�
    printf("%d\n", *ptr);   // Skriv ut talet
}

void print_array(int *arr)
{
    // Skriv ut varje v�rde i en array (fast l�ngd 5)
    for (int i=0; i<5; i++)
    {
        printf("%d\n", arr[i]);
    }
}
