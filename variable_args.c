#include <stdarg.h>
#include <stdio.h>

// The function signature uses '...' to indicate variadic arguments
int sum_integers(int count, ...) {
    // 1. Declare a va_list variable
    va_list args; 
    int sum = 0;
    
    // 2. Initialize the list: 'count' is the last fixed argument
    va_start(args, count); 

    // 3. Loop through the count and retrieve each argument
    for (int i = 0; i < count; i++) {
        // va_arg retrieves the next argument, expecting it to be an 'int'
        sum += va_arg(args, int); 
    }

    // 4. Clean up the list
    va_end(args); 

    return sum;
}

int main() {
    int result = sum_integers(4, 10, 20, 5, 15); // count = 4, followed by 4 integers
    printf("The sum is: %d\n", result); // Output: The sum is: 50
    return 0;
}
