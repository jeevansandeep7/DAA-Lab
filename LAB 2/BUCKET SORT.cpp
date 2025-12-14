#include <stdio.h>

int main() {
    int n, i, j, k;
    scanf("%d", &n);
    int arr[n];

    int bucket[10][100], count[10] = {0};

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        int index = arr[i] / 10;
        bucket[index][count[index]++] = arr[i];
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < count[i] - 1; j++) {
            for (k = 0; k < count[i] - j - 1; k++) {
                if (bucket[i][k] > bucket[i][k + 1]) {
                    int temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    for (i = 0; i < 10; i++)
        for (j = 0; j < count[i]; j++)
            printf("%d ", bucket[i][j]);

    return 0;
}

