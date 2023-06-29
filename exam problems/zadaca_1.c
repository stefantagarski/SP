//Дадена е текстуална датотека text.txt.
//Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во датотеката.
// Појавата на големи и мали букви да се игнорира.
// Пронајдените парови самогласки да се испечатат на екран, секој во нов ред со мали букви.
// Потоа во нов ред се печати бројот на појавувања на паровите самогласки.
#include <stdio.h>
#include <ctype.h>
void writeToFile() {
    FILE *f = fopen("text.txt", "w");
    char c;

    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}
int is_vowel(char c){
   if(tolower(c)){
       if(c == 'a'|| c == 'e' || c == 'o' || c == 'i'|| c == 'u' ){
           return 1;
            }
        }
    return 0;
    }
int main() {
    writeToFile();
    // Vasiot kod zapocnuva od tuka
    FILE *f = fopen("text.txt","r");
    char c, p;
    int found = 0;
    while ((c=fgetc(f))!=EOF) {
        c = tolower(c);
        p = tolower(p);
        if (is_vowel(c)&&is_vowel(p)){
            printf("%c%c\n", p, c);
            found++;
        }
        p = c;
    }
    fclose(f);
    printf("%d", found);
    return 0;
}
