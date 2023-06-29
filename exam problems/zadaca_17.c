//Од тастатура се внесуваат димензиите на една матрица (m,n <= 100), а потоа и елементите од матрицата.
// Да се трансформира матрицата така што средниот елемент во секоја редица ќе се замени со разликата (по апсолутна вредност)
// на сумата на елементите во првата половина од редицата и сумата на елементите во втората половина на редицата.
// Ако матрицата има парен број колони, се менува вредноста на средните два елемента.
// Средниот/те елемент/и влегува/ат во сумите (при непарен број на колони, средниот елемент влегува во двете суми!).
// Да се испечати на екран променетата матрица.

#include<stdio.h>
#include<stdlib.h>
int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        int first_half_sum = 0;
        int second_half_sum = 0;
        int middle_index = n / 2;
        for (int j = 0; j < middle_index; j++) {
            first_half_sum += a[i][j];
        }
        for (int j = middle_index + (n % 2); j < n; j++) {
            second_half_sum += a[i][j];
        }
        if(n % 2 == 0) {
         a[i][middle_index - 1] = abs((first_half_sum - second_half_sum));
         a[i][middle_index] = abs(first_half_sum - second_half_sum);
        } else{
            a[i][middle_index] = abs(first_half_sum - second_half_sum);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
