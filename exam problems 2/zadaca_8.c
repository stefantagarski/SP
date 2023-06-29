//zadaca_9.
//input : Svrznicite vo makedonskiot jazik se sluzbeni zborovi
//odnosno niv gi upotrebuvame za povrzuvanje oddelni zborovi
//vo ramkite na edna recenica ili poveḱe recenici vo edna slozena recenica.
//Pri povrzuvanjeto, svrznicite gi izrazuvaat odnosite megju zborovite
//ili megju recenicite, pa taka sprotiven odnos se iskazhuva so
//ama ili no, a usloven odnos so ako itn.
// result : 7: ama ili no, a usloven odnos so ako itn.

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void cleanString(char *str) {
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}
int countConjunctions(char *str) {
    int inWord = 0;
    int len = 0;
    int conjunctions = 0;
    while (*str) {
        if (isalpha(*str)) {
            inWord = 1;
            ++len;
        } else {
            if (len > 0 && len <= 3) {
                ++conjunctions;
            }
            len = 0;
            inWord=0;
        }
        ++str;
    }
    if (len<=3 && inWord) {
        ++conjunctions;
    }
    return conjunctions;
}

int main() {
    char line[100];
    int maxConjunctions = 0;
    char maxLine[100];
    int first = 1;
    while (fgets(line, sizeof(line), stdin)) {
        if (first) {
            strcpy(maxLine, line);
            first = 0;
        }

        cleanString(line);
        int conjunctions = countConjunctions(line);
        if (conjunctions>maxConjunctions) {
            strcpy(maxLine, line);
            maxConjunctions = conjunctions;
        }
    }

    printf("%d: %s", maxConjunctions, maxLine);
    return 0;
}
