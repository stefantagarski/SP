//Од стандарден влез се чита природен број N (N <= 100), како и низа од позитивни цели броеви a[ ] со N елементи.
//Да се напише функција int par(a, n) која ќе го врати најмалиот елемент во низата кој се појавува парен број пати во низата.
// Доколку нема таков елемент, функцијата враќа вредност 0.
//Напишете програма што ќе ја повика функцијата par за внесената низа a[ ] и ќе го испечати најмалиот број
// којшто се појавува парен број пати во низата a[ ].

#include <stdio.h>
int par(int arr[], int n)
{
    int i, j, count;
    int min = arr[0];
    int flag = 0;

    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count % 2 == 0)
        {
            flag = 1;
            if (arr[i] < min)
                min = arr[i];
        }
    }

    if (flag)
        return min;
    else
        return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int result = par(a, n);
    if(result == 0 ){
        printf("Nitu eden element ne se pojavuva paren broj pati!\n");
    }
    else{
        printf("Najmaliot element koj se pojavuva paren broj pati e %d",result);
    }
    return 0;
}
