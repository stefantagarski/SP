//Zadaca.15

#include <stdio.h>

int poramneti(int a) {
    if (a == 0) {
        return 0;
    }
    int last_digit = a % 10;
    if (last_digit == 9) {
        last_digit = 7;
    }
    return poramneti(a/10) *10 +last_digit;
}
int main() {
    int n, i, a, arrays[100], count = 0;
    while (scanf("%d", &a)) {
       arrays[count] = poramneti(a);
        count++;
    }
    if (count == 0) {
        return 0;
    }
    int temp;
    for (i = 0; i < count; i++) {
        for (n = i + 1; n < count; n++) {
            if (arrays[i] > arrays[n]) {
                 temp = arrays[i];
                arrays[i] = arrays[n];
                arrays[n] = temp;
            }
        }
    }
    if( count < 5){
        n = count;
    }
    else {
        n = 5;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", arrays[i]);
    }
    return 0;
}
