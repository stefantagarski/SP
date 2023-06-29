//Од тастатура се внесуваат димензиите m и n на матрица од цели броеви, Аmxn, ( 0 < m, n < 30 ) и нејзините елементи.
// Потоа се внесуваат два цели броја r и k  (индекси на редица/колона од матрицата, т.е. 0 <= r < m и 0 <= k < n).
//Да се напише програма која ja трансформира матрицата А така што елементите над редицата r и лево од колоната
// k се заменуваат со минималната вредност од матрицата А.
//Новодобиената матрица да се запише во датотека "matrica.txt".

#include <stdio.h>
void printFile() {

    FILE *f=fopen("matrica.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int main(){
    int n, m, r, k, min;
    int mtr[30][30];
    scanf("%d%d", &m, &n);
    scanf("%d%d", &r, &k);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &mtr[i][j]);
            if(i == 0 && j == 0)
                min = mtr[i][j];
            else if(mtr[i][j] < min)
                min = mtr[i][j];
        }
    for(int i = 0; i < r; i++)
        for(int j = 0; j < k; j++)
            mtr[i][j] = min;
    FILE *fp = fopen("matrica.txt", "w");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            fprintf(fp, "%d ", mtr[i][j]);
        fprintf(fp, "\n");
    }
    fclose(fp);
    printFile();
    return 0;
}
