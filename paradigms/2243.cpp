# URL: https://www.beecrowd.com.br/judge/en/problems/view/2243


#include <bits/stdc++.h>


using namespace std;

int vetor[50001];

int main() {
        int n; cin >> n;
        for( int i=0; i<n; i++)
                cin >> vetor[i];
        int aux = 1, maxi = 0;
        vetor[0] = min( 1, vetor[0] );
        for( int i=1; i<n; i++ ) {
                vetor[i] = min( vetor[i], vetor[i-1] + 1 );
        }
        vetor[n-1] = min( vetor[n-1], 1 );
        for( int i=n-2; i>= 0; i-- ){
                vetor[i] = min( vetor[i], vetor[i+1] + 1 );
                if( vetor[i] > maxi ) maxi = vetor[i];
        }
        printf("%d\n", maxi );

return 0;
}
