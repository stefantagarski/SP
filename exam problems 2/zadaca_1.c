//Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци. Низите знаци содржат букви,
// цифри и специјални знаци (без знаци за празно место), а секоја од нив не е подолга од 80 знаци.
//Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата низа, којашто е палиндром
// (се чита исто од од лево на десно и од десно на лево) и што содржи барем еден специјален знак.
// Ако нема такви низи, се печати "Nema!".
// Ако има две или повеќе низи што го задоволуваат овој услов, се печати првата низа којашто го задоволува условот.


#include<stdio.h>
#include<string.h>
#include<ctype.h>
void cleanString( char * str){
    if(str[strlen(str) - 1] == '\n'){
        str[strlen(str) - 1] = '\0';
    }
}
int checkCondition(char *str ){
    int isPalindrome = 1, hasSpecial = 0;
    int n = strlen(str);
    for (int i = 0; i < n/2; ++i) {
        if(str[i] != str[n - i - 1]){
            isPalindrome = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!isalnum(str[i]) ){
            hasSpecial = 1;
        }
    }
    return isPalindrome == 1 && hasSpecial == 1;
}
int main (){
    int n;
    scanf("%d",&n);
    int maxL = 0;
    char maxLine[81];
    for (int i = 0; i < n; ++i) {
        char line[81];
        fgets(line, sizeof(line),stdin);
        cleanString(line);
        if(checkCondition(line)){
            if (line > maxL){
                maxL = strlen(line);
                strcpy(maxLine,line);
            }
        }
    }
    if(maxL){
        puts(maxLine);

    }
     else{
        printf("nema!");
    }
    return 0;
}
