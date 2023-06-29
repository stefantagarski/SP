//Да се напише програма која вчитува матрица со димензии MxN (макс. 100x100). На почетокот се внесуваат димензиите на матрицата,
// а потоа и елементите на матрицата
// кои се само вредностите 1 и 0. Програмата треба да изброи и отпечати на СИ во колку од
// редиците и колоните има барем 3 последователни елементи со вредност 1.

#include <stdio.h>
int main() {

    int rows, cols;
    scanf("%d %d", &rows,&cols);
    int matrix[100][100];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int row_count = 0;
    int col_count = 0;
    for (int i = 0; i < rows; i++) {
        int consecutive_ones = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                consecutive_ones++;
                if (consecutive_ones >= 3) {
                    row_count++;
                    break;
                }
            } else {
                consecutive_ones = 0;
            }
        }
    }
    for (int j = 0; j < cols; j++) {
        int consecutive_ones = 0;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 1) {
                consecutive_ones++;
                if (consecutive_ones >= 3) {
                    col_count++;
                    break;
                }
            } else {
                consecutive_ones = 0;
            }
        }
    }


    printf("%d",row_count+col_count);

    return 0;
}


