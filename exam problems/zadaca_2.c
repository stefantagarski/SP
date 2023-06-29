//Во дадена датотека “broevi.txt” се запишани повеќе редови со броеви така што секој ред започнува со еден цел број (N>=1) 
//што означува колку броеви следуваат по него во тој ред.
//Да се напише програма која на СИ за секој ред ќе го испечати бројот со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се прочита 0.
#include <stdio.h>
//ne menuvaj!
void wtf() {
    FILE *f = fopen("broevi.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main()
{
    wtf();
    FILE *f = fopen("broevi.txt", "r");
    int n, num, max, maxDigit;
    fscanf(f, "%d", &n);
    while (n != 0) {
        max = 0;
        maxDigit = 0;
        for (int i = 0; i < n; i++) {
            fscanf(f, "%d", &num);
            int digit = num;
            while (digit >= 10) {
                digit /= 10;
            }
            if (digit > maxDigit) {
                maxDigit = digit;
                max = num;
            }
        }
        printf("%d\n", max);
        fscanf(f,"%d",&n);
    }
    fclose(f);

    return 0;
}
