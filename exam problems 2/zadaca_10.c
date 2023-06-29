//zadaca_11

#include <stdio.h>
void shift_array(int arr[], int n) {
    int shift = arr[0];
    int i;

    if (shift > 0) {
        for (i = n - 1; i >= shift; i--) {
            arr[i] = arr[i - shift];
        }
        for (i = 0; i < shift; i++) {
            arr[i] = 0;
        }
    } else if (shift < 0) {
        shift = -shift;
        for (i = 0; i < n - shift; i++) {
            arr[i] = arr[i + shift];
        }
        for (i = n - shift; i < n; i++) {
            arr[i] = 0;
        }
    }
}


int is_empty(int a[],int n) {
    for (int i = 0; i < n; i++)
        if (a[i] != 0) {
            return 0;
        }
            return 1;
        }
int main() {
    int m,l=0;
    scanf("%d", &m);
    int empty_count = 0;
    while(l < m) {
        int n;
        scanf("%d", &n);
        int a[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        shift_array(a, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        if (is_empty(a, n)) {
            empty_count++;
        }
    l++;
    }
    printf("%d", empty_count);

    return 0;
}
