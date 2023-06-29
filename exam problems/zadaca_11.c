//Да се напише програма во која од дадена датотека со име "input.txt" за секој ред ќе се отпечати бројот на цифри во тој ред, знакот :,
// па самите цифри подредени според ASCII кодот во растечки редослед. Редовите во датотеката не се подолги од 100 знаци.
#include <stdio.h>
#include <string.h>
void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
    FILE *file = fopen("input.txt", "r");

    char line[101];
    int digits[10], count = 0;
    while (fgets(line, sizeof(line), file)) {
        memset(digits, 0, sizeof(digits));
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                digits[line[i] - '0']++;
                count++;
            }
        }
        printf("%d:", count);
        count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < digits[i]; j++) {
                printf("%d", i);
            }
        }
        printf("\n");
    }

    return 0;
}
