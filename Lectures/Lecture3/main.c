#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    const char *my_str = get_hello_string();
    printf("%s\n", my_str);

    print_this_string(my_str);

    /*
    print_a_number();

    int my_num = give_me_a_number();

    printf("%d\n", my_num);

    print_this_number(42);

    int my_arr[] = {5, 4, 3, 2, 1};
    print_array(my_arr);

    int age = 37;

    print_int_pointer(&age);
*/
    /*
    char myString[] = "This is a string";

    int counter;

    for(counter = 0 ; myString[counter] != '\0' ; counter++);
*/
    /*
    // Räkna alla vanliga tecken, ignorerar mellanslag
    for(int i = 0; myString[i] != NULL, i++)
    {
        if (myString[i] != ' ')
        {
            counter++;
        }
    }*/
/*
    int while_counter = 0;

    char *my_char_pointer;  // Pekare till ett tecken i strängen
    my_char_pointer = myString;

    while (*my_char_pointer != '\0')  // *: Är värdet null?
    {
        while_counter++;
        my_char_pointer++;
    }


    printf("Length with for-loop: %d\n", counter);
    printf("Length with while-loop: %d\n", while_counter);
*/
    /*
    int values[] = {10, 20, 30, 40, 50};

    printf("%d\n", *values);
    printf("%d\n", *(values+1));
    printf("%d\n", *(values+2));
    printf("%d\n", *(values+3));
    printf("%d\n", *(values+4));

    // Spara adressen till tredje värdet i arrayen?

    int *value_ptr = (values + 2);
    printf("%p\n", value_ptr);
    printf("%d\n", *value_ptr);

    char s[] = "My String";

    printf("%s", strrev(s));
    */
/*
    int age = 37;

    printf("%d\n", age);
    printf("%p\n", &age);

    // Skapa en variabel som kan lagra en minnesaddress till ett heltal
    // Kopiera addressen till "age"-variabeln
    int *age_pointer = &age;

    printf("%p\n", age_pointer); // Age_pointer innehåller en address
    printf("%d\n", *age_pointer); // Skriv ut värdet som addressen pekar på

    float almost_pi = 3.1;
    float *a_pi_pointer = &almost_pi;

    printf("%f\n", almost_pi);
    printf("%p\n", &almost_pi);
*/
    return 0;
}

void print_int_pointer(int *ptr)
{
    printf("%p\n", ptr);
    printf("%d\n", *ptr);
}

void print_array(int *arr)
{
    for (int i=0; i<5; i++)
    {
        printf("%d\n", arr[i]);
    }
}
