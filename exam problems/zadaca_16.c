//Да се напише рекурзивна функција за наоѓање на максималната цифра од даден цел број.
//Од стандарден влез се внесуваат непознат број цели броеви се додека не се внесе нешто што не е број.
// За секој од нив да се испечати максималната цифра во посебен ред.
//Забелешка: Решението со рекурзивна функција носи 100% од поените, а со нерекурзивна функција 70% од поените.
//Забелешка: ЗАБРАНЕТО е користење на глобални променливи.

#include <stdio.h>
int max_digit( int n) {
    if (n < 10) {
        return n;
    } else {
        int last = n % 10;
        int remain = n / 10;
        if (last > max_digit(remain)) {
            return last;
        }
        else{
            return max_digit(remain);
        }
    }
}
int main() {
    int n;
    while(scanf("%d",&n)){

        printf("%d\n",max_digit(n));
    }
    return 0;
}
