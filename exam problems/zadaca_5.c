//Дадена е текстуална датотека (livce.txt) која претставува ливче во спортска обложувалница.
//На почетокот во датотеката, во посебен ред е запишана сумата на уплата (цел број).
//Потоа во секој ред од датотеката е запишан по еден тип во следниот формат:
//ab12 1 1.25
//Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци), вториот број е типот (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).
//Ваша задача е да се испечати типот со најголем коефициент како и можната добивка на ливчето. Доколку има повеќе типови со ист максимален коефициент, да се испечати првиот.
//Можната добивка се прсметува како производ на сите коефициенти со сумата на уплата.

#include <stdio.h>
#include<string.h>

// ne menuvaj ovde
void wf() {
    FILE *f = fopen("livce.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wf();
    char typeCode[10];
    int tip ,maxtip;
    double coefficient, maxCoefficient = 0;
    double vlog, proiznakoef = 1;
    char maxTypeCode[10];

    FILE *f = fopen("livce.txt","r");
    fscanf(f, "%lf", &vlog);
    while (fscanf(f, "%s %d %lf", typeCode, &tip, &coefficient) == 3) {
        if (coefficient > maxCoefficient) {
            maxCoefficient = coefficient;
            strcpy(maxTypeCode, typeCode);
            maxtip = tip;
        }
        proiznakoef *= coefficient;
    }
    fclose(f);
    printf("%s %d %.2lf\n", maxTypeCode, maxtip, maxCoefficient);
    printf("%.2lf\n", vlog * proiznakoef);


    return 0;

}
