#include <stdio.h> //for printf

int main(void) // actual stuff happens here
{

    /*
    printf has two parts
        Format string: Tell you what to print and how to print it
        Values: Whatever are the values of the variabels
    */
    int i = 2;
    float f = 3.14;
    char *s = "Hello, world!"; // char * ("char pointer") is the string type
    /*
        %d for int , %f for float, %s for string
    */
    printf("%s  i = %d and f = %f!\n", s, i, f);
}
