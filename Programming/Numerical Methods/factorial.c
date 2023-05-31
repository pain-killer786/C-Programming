#include <stdio.h>

int factorial(int n) {
    int result = 1;
    
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int num;
    printf("Enter a integer: ");
    scanf("%d", &num);
    
    
        int fact = factorial(num);
        printf("Factorial of %d is %d.\n", num, fact);
    
    
    return 0;
}
