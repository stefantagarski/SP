//Да се имплементира рекурзивна функција која за низа од цели броеви $[a{0}, a{1}, ..., a_{n-1}]$
// ќе ја пресмета вредноста на непрекинатата дропка дефинирана како
//v=a0+1a1+...1an−2+1an−1
//Да се напише програма во која се чита цел број N, по што се читаат елементите на низа од N цели броеви (не повеќе од 100).
// Потоа се повикува рекурзивната функција и се печати резултатот во нов ред.'


#include<stdio.h>
double fraction (double array[],int n,int a);
int main(){
    int n;
    scanf("%d",&n);
    double array[n];
    for(int i = 0;i < n;i++){
        scanf("%lf",&array[i]);
    }
    double
     v = fraction(array, n, 0);
    printf("%lf",v);
    return 0;
}
double fraction ( double array[],int n,int a){
    if(a == n-1){
        return array[a];
    }
    else{
        return   array[a] + 1.0 / fraction(array,n,a+1);
    }
}
