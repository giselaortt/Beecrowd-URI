#URL: https://www.beecrowd.com.br/judge/en/problems/view/1980



#include <bits/stdc++.h>

using namespace std;

long long int vetor[16];

long long int funcao(int A){
    if(A == 1) return 1;
    if(vetor[A] != 0 ){
      return vetor[A];
    }
    long long int resp;
    resp = A*funcao(A-1);
    vetor[A] = resp;
    return resp;
}

int main(){
    string S;
    int m, i;
    long long int resp[500];
    for( m = 0; 1 ; m++ ){
        cin >> S;
        if(S[0] == '0') break;
        resp[m] = funcao(S.size());
    }
    for(i=0;i<m;i++){
        printf("%lld\n", resp[i]);
    }

return 0;
}
