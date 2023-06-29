//Во рамките на текстуална датотека matrica.txt се сместени елементите (целобројни вредности) од една матрица (A).
// Во првиот ред од датотеката се запишани бројот на редици n и бројот на колони m на матрицата (n, m < 120).
// Потоа, во секој ред од датотеката се запишани елементите од соодветната редица на матрицата.
//Да се испечати колку индексни броеви има во секоја колона поединечно.
//Индексен број е број чија вредност е идентична со вредноста што се добива со спојување на индексот од редицата и колоната на елементот.


#include<stdio.h>
void wtf() {
    FILE *f = fopen("matrica.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}
int main() {
    wtf();

    FILE *dat = fopen("matrica.txt", "r");
    int matrix[120][120];
    int n, m, num;
    fscanf(dat, "%d %d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(dat, "%d", &matrix[i][j]);
        }
    }
    for (j = 0; j < m; j++) {
        int index_count = 0;

        for (i = 0; i < n; i++) {

              if(j < 10) {
                  num = i * 10 + j;
              }
               else if (j < 100) {
                  num = i * 100 + j;
              }
               else {
                   num = i * 1000 + j;
               }
            if (num == matrix[i][j])
                index_count++;
        }
        printf("%d\n", index_count);
    }
    fclose(dat);
    return 0;
}
