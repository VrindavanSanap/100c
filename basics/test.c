#include <stdio.h>
#include <string.h>

int main() {
    const char *s1 = "String";
    char *s2;
    
    s2 = s1;  // Assign s1 to s2
    
    printf("s1: %s\n", s1);  // Output: String
    printf("s2: %s\n", s2);  // Output: String
    
    s2[0] = 's';  // Modifying s2 affects s1
    
    printf("s1: %s\n", s1);  // Output: string (unexpectedly modified)
    printf("s2: %s\n", s2);  // Output: string (same as s1)
    
    return 0;
}

