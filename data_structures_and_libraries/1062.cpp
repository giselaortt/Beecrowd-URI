#URL: https://www.beecrowd.com.br/judge/en/problems/view/1062



#include <bits/stdc++.h>
#define MAXI 100000

using namespace std;

const int inf = 100000001;

int vetor[MAXI];
stack<int> pilha;

int main(){
    int N, A, next;
    bool good;

    while(true){
        cin >> N;
        if( N == 0 ) break;
        while( true ){
            while( !pilha.empty() ) pilha.pop();
            next = N;
            cin >> vetor[0];
            if( vetor[0] == 0 ) break;
            for( int i=1; i<N; i++ ) cin >> vetor[i];

            for( int i=N-1; i>=0; i-- ){
                if( vetor[i] != next ) pilha.push( vetor[i] );
                else{
                    next--;
                    while( pilha.size() && pilha.top() == next ){
                        pilha.pop();
                        next--;
                    }
                }
            }
            if( pilha.empty() ) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }

return 0;
}
