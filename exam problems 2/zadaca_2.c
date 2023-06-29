//Од тастатура се чита природен број N (N < 400).
//Да се напише програма којашто формира квадратна матрица што ги содржи броевите од 1 до N по растечки редослед на
// следниот начин: во првата колона во правец од горе надолу, па продолжува во втората колона од долу нагоре,
// па продолжува во третата колона од горе надолу итн.
// Да се избере најмалата димензија на матрицата во која ќе ги собере сите броеви до N.
// Доколку има преостанати празни места, тие да се пополнат со нули.

#include <stdio.h>
#include<math.h>
void printFile() {
    FILE *f=fopen("shema.txt","r");
    char line[1000];
    while(!feof(f)){
        fgets(line,1000,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int main() {
    int n;
    scanf("%d",&n);
    int dimenzija = ceil(sqrt(n));
    int mtr[dimenzija][dimenzija];
    for(int i = 0;i < dimenzija;i++){
        for(int j =0 ;j < dimenzija;j++){
            mtr[i][j] = 0;
        }
    }
    int number = 1; //flag
    for(int j = 0;j < dimenzija;j++){
        if(j % 2 == 0){
            for(int i = 0;i < dimenzija;i++){ // od gore pa nadolu
                if(number <= n){
                    mtr[i][j] = number;
                    number++;
                }
            }
        }
        else{
            for(int i = dimenzija -1; i >= 0; i--){  // od nadolu pa nagore
                if(number <= n){
                    mtr[i][j] = number;
                    number++;
                }
            }
        }
    }
    for(int i = 0;i < dimenzija;i++){
        for(int j = 0 ;j < dimenzija;j++){
            printf("%d ",mtr[i][j]);
        }
        printf("\n");
    }
    FILE *file = fopen("shema.txt", "w");
    for (int i = 0; i < dimenzija; ++i) {
        for (int j = 0; j < dimenzija; ++j) {
            fprintf(file,"%d ",mtr[i][j]);
        }
        fprintf(file,"\n");
    }
    printFile();
    return 0;
}
