//Од стандарден влез се чита цел број N (N<100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци,
// а секоја од нив не е поголема од 50 знаци.
//Да се напише програма што ќе ги отпечати на екран сите низи од знаци во кои се содржи поднизата А1c  најмалку 2 пати
// (пр. A1c01АA1c92, 12A1cwwA1cxy, аA1cwA1cA1ccA1cxab)
// според редоследот како што се прочитани од влезот. При печатење на зборовите, сите алфабетски знаци треба да се испечатат со мали букви.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[100];
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        int no_occ = 0;
        int j;
        for (j = 0; j < strlen(str) - 2; j++) {
            if (tolower(str[j]) == 'a' && str[j + 1] == '1' && tolower(str[j + 2]) == 'c') {
                no_occ++;
            }
        }
        if (no_occ >= 2) {
            for (j = 0; j < strlen(str); j++)
                printf("%c", tolower(str[j]));
            printf("\n");
        }
    }
    return 0;
}
