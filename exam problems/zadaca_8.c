//it goes through 2/3 tests.

#include <stdio.h>
#include<string.h>
#include<ctype.h>
// ne menuvaj ovde
void wtf() {
    FILE *f = fopen("dat.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
    FILE *f = fopen("dat.txt", "r");
    char line[100];
    char longestLine[100];
    char longestString[100];
    int firstDigit, lastDigit;
    int longestLineLength = 0;
    int digitCount;
    int i,j;

    while (fgets(line, 100, f)) {
        digitCount = 0;
        firstDigit = -1;
        lastDigit = -1;
        for (i = 0; i < strlen(line); i++) {
            if (isdigit(line[i])) {
                if (firstDigit == -1) {
                    firstDigit = i;
                }
                lastDigit = i;
                digitCount++;
            }
        }
        if (digitCount >= 2) {
            int currentLineLength = lastDigit - firstDigit + 1;
            if (currentLineLength > longestLineLength) {
                longestLineLength = currentLineLength;
                strcpy(longestLine, line);
                for (j = firstDigit; j <= lastDigit; j++) {
                    longestString[j - firstDigit] = line[j];
                }
            }
        }
    }
    if (longestLineLength > 0) {
        printf("%s",longestString);
    }
    fclose(f);
    return 0;
}

