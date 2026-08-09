#include <stdio.h>

int swap(int *a, int *b);

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d%d", &x, &y);
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}

int swap(int *a, int *b) {
    int temp;
    temp = *a;  // 1. Save the value of 'a' into temp
    *a = *b;    // 2. Put the value of 'b' into 'a'
    *b = temp;  // 3. Put the saved temp value into 'b'
    
    return 0;   // Added to match your 'int' return type
}
