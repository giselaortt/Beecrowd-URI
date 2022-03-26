#URL: https://www.beecrowd.com.br/judge/en/problems/view/1029


//fibonaci
#include <bits/stdc++.h>

using namespace std;

int ctd = 0;
int vetor[2000];
int resp[2000];
int resp2[2000];

long int funcao(int A){
    ctd ++;
    if(A == 0) return 0;
    if(A == 1) return 1;
    return funcao(A-1) + funcao(A-2);
}

int main(){
    int A, i;
    scanf("%d", &A);
    for(i=0;i<A;i++){
        scanf("%d", &vetor[i]);
        resp[i] = funcao(vetor[i]);
        resp2[i] = ctd - 1;
        ctd = 0;
    }
    for(i=0;i<A;i++){
        printf("fib(%d) = %d calls = %d\n", vetor[i], resp2[i], resp[i]);
    }

return 0;
}
