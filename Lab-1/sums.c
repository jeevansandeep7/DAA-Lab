#include <stdio.h>
int sumNaturalNumbers(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int result = sumNaturalNumbers(n);
    printf("Sum of first %d natural numbers = %d\n", n, result);
    return 0;
}