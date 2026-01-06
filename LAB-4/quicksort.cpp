#include <stdio.h>
int arrange(int list[], int left, int right) {
    int pivotValue = list[right];
    int boundary = left - 1;
    int tempValue;
    for (int current = left; current < right; current++) {
        if (list[current] <= pivotValue) {
            boundary++;
            tempValue = list[boundary];
            list[boundary] = list[current];
            list[current] = tempValue;
        }
    }
    tempValue = list[boundary + 1];
    list[boundary + 1] = list[right];
    list[right] = tempValue;
    return boundary + 1;
}
void quickArrange(int list[], int left, int right) {
    if (left < right) {
        int splitPoint = arrange(list, left, right);
        quickArrange(list, left, splitPoint - 1);
        quickArrange(list, splitPoint + 1, right);
    }
}
int main() {
    int count, values[50], index;
    printf("Enter number of elements: ");
    scanf("%d", &count);
    printf("Enter elements:\n");
    for (index = 0; index < count; index++)
        scanf("%d", &values[index]);
    quickArrange(values, 0, count - 1);
    printf("Sorted array:\n");
    for (index = 0; index < count; index++)
        printf("%d ", values[index]);
    return 0;
}
