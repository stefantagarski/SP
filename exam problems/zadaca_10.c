//zadaca_10

#include <stdio.h>
#include <string.h>

// ne menuvaj ovde
void wtf() {
    FILE *f = fopen("podatoci.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}
void cleanString (char *str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) -1] = '\0';
    }
}
void substring(char *line, char z1, char z2) {
    char *c1, *c2, newS[81];
    c1 = strchr(line, z1);
    c2 = strchr(line, z2);
    strncpy(newS, c1+1, c2-c1);
    newS[c2-c1-1] = '\0';
    printf("%s\n", newS);

}
int main() {
    wtf();
    getchar();
    char z1, z2;
    char line[81];
    FILE* f = fopen("podatoci.txt","r");
    z1 = getchar();
    z2 = getchar();
    while(fgets(line, sizeof (line), f) != NULL) {
        cleanString(line);
        substring(line, z1, z2);
    }
    fclose(f);
    return 0;
}
