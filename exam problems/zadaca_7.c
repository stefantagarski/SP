//Од тастатура се внесуваат димензиите на една матрица (m, n <= 100), а потоа и елементите од матрицата.
// Да се генерира низа (со најмногу m) така што секој елемент од низата се добива со наоѓање на
// елементот во секоја редица од матрицата што е најоддалечен од аритметичката средина во рамки на таа редица.
// Ако постојат повеќе елементи што се најоддалечени од аритметичката средина, тогаш се зема предвид првиот.
// Редоследот на запишување на елементите во низата одговара на редоследот на редиците.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    double matrix[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    double farthest[100];
    for (int i = 0; i < m; i++) {
        double row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += matrix[i][j];
        }
        double avg = row_sum / n;
        double max_distance = 0;
        int max_index = 0;
        for (int j = 0; j < n; j++) {
            double distance = fabs(matrix[i][j] - avg);
            if (distance > max_distance) {
                max_distance = distance;
                max_index = j;
            }
        }
        farthest[i] = matrix[i][max_index];
    }
    for (int i = 0; i < m; i++) {
        printf("%lf ", farthest[i]);
    }
    printf("\n");
    return 0;
}
