#include <stdio.h>
#include "calculate_age.h"

// Declare new types and constants here
typedef enum{
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday
    } WEEKDAY;

typedef struct {
    int age;
    char *name;
} PERSON;

// define a symbolic constant
#define VALUE 1
#define PI 3.14
#define NAME "Flavio"

// Define a macro
#define POWER(x) ((x) * (x))

// int main(void) {
// To accept parameters from the command line when the command launches
int main(int argc, char *argv[]) {

    printf("Hello World!\n");

    // Implicit conversion is performed since age is an integer.
    int age = 0;
    age = 26.5;
    printf("%u\n", age);

    // How overflow works?
    // Case 1: if the range is exceeded for unsigned
    unsigned char j = 255;
    j = j + 10;
    printf("%u\n", j);
    // Case 2: if the range is exceeded for signed
    char k = 255; /* This value will overflow in the memory since a char range value is (-128, 127)*/
    k = 127;
    k += 10;
    printf("%u\n", k);
    // KEEP IN MIND: C does not protect you from going over the limits of a type.
    // You need to take care of this yourself.

    char m = 1000; /*Compiler warns me about overflow at the initialization*/
    char n;
    n = 1000; /*Compiler warns me about overflow at assignment*/
    char p = 0;
    p = p + 1000; /*Compiler does not warn if you increase*/

    // FIRST THING I MUST DO AS A SOFTWARE ENGINEER: BE AWARE OF THE SPECIFIC SIZE OF TYPES ON THE COMPUTER I AM WORKING ON
    // IF IT IS FOR A CLIENT, I MUST ASK FOR THE DEVICES HE IS PLANNING TO DEPLOY MY WORK ON.
    printf("\n\nLet's determine the specific size of types on my computer!\n");
    printf("char size: %lu bytes\n", sizeof(char));
    printf("short size: %lu bytes\n", sizeof(short));
    printf("int size: %lu bytes\n", sizeof(int));
    printf("float size: %lu bytes\n", sizeof(float));
    printf("long size: %lu bytes\n", sizeof(long));
    printf("double size: %lu bytes\n", sizeof(double));
    printf("long double size: %lu bytes\n\n", sizeof(long double));

    //  About constants declaration
    const float height = 72.5;
    const float MY_HEIGHT = 72.5; /*Uppercase for constant to increase code readability*/
    #define HEIGHT 72.5 /* you don't need to add a type, and you don't also need the
                            equal sign, and you omit the semicolon at the end.
                            The C compiler will INFER THE TYPE from the value specified, at compile time.*/

    int my_age = 37;
    printf("%ld\n", sizeof(my_age));
    printf("%ld\n\n", sizeof(int));

    // printf(" BOOOOOOOLEEANNNN: %ld\n\n", sizeof(bool)); // There is no boolean type in C? There is a boolean type called: bool
    // Boolean is not working. Why? 
    
    // POINTERS
    int *address, *another_address,  another_age;
    address = &age;
    another_address = &another_age;
    printf("ABOUT POINTERS \n\n");
    printf("%p\n", &age);
    printf("%u\n", *address); /*Get the value of the variable it is pointing to.*/

    *another_address = 33; /* Initialize another age using the pointer */
    printf("Another age value is: %u\n", another_age);
    printf("Another address value is: %u\n\n", *another_address);

    int prices[3] = {5, 4, 3};
    printf("First price: %u\n", *prices); /*Arrays are 0-indexed. This is equivalent to *(prices + 0)*/
    printf("Second price: %u\n", *(prices + 1));
    printf("Third price: %u\n", *(prices + 2));

    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("you entered %s\n\n", name); /*It does not print all my name whenever I separate it with spaces. Why?*/

    // STATIC VARIABLE: a variable which initialixed at 0 if no initial value is specified
    // and it retains the value across function calls.

    // int incrementAge(){
    //     static int age;
    //     age++;
    //     return age;
    // }
    /* We can also omit initializing age to 0 in static int age = 0; , and just write
        static int age; because static variables are automatically set to 0 when created. */

    // printf("Increment age\n");
    // printf("%d\n", incrementAge());
    // printf("%d\n", incrementAge());
    // printf("%d\n", incrementAge());
    // printf("%d\n", incrementAge());
    // printf("%d\n", incrementAge());
    // printf("%d\n", incrementAge());

    // int incrementAgeArray(){
    //     static int ages[3];
    //     ages[0]++;
    //     return ages[0];
    // }

    // printf("Increment age array\n");
    // printf("%d\n", incrementAgeArray());
    // printf("%d\n", incrementAgeArray());
    // printf("%d\n", incrementAgeArray());
    // printf("%d\n", incrementAgeArray());
    // printf("%d\n", incrementAgeArray());

    printf("\n\nTypes definition: enumerate and strctures\n");
    WEEKDAY day = wednesday;

    if (day == wednesday) { 
        /* 
        * this condition is equivalent since every item in the enum definition
        * is paired to an integer, internally: if (wednesday = 2) {
        */
        printf("It is Wednesday\n");
    } else {
        printf("It is not Wednesday\n");
    }

    PERSON feujio = { 20, "Feujio"};
    printf("%s, age %u\n", feujio.name, feujio.age);

    printf("List of arguments from command line\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    // This system works great for simple needs. For more complex needs, there are commonly used packages like **getopt**


    // Header files
    printf("\n\nHeader files\n");
    printf("%u\n", calculateAge(1983));
    // And with more complex setups, a Makefile is necessary to tell the compiler how to compile the program.

    // PREPROCESSOR
    // It parses our program and makes sure that the compiler gets all the things it needs before going on with the process
    // Symbolic constants are very useful because we can give names to values without creating variables at compilation time.
    
    // Use a macro
    printf("\n\nUse macro to compute the power of 4: %u\n", POWER(4)); //16
    // The big difference with functions is that macros do not specify the type of
    // their arguments or return values, which might be handy in some cases.
    // Can we have multiline macros?

    // If defined (#ifdef) and if not defined (#ifndef)
    // We can check if a symbolic constant or a macro is defined using #ifdef :
    #ifdef VALUE
        printf("Value is defined\n");
    #else
        printf("Value is not defined\n");
    #endif

    printf("\n\n\n");
    return 0;
}