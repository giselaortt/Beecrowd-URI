#URL: https://www.beecrowd.com.br/judge/en/problems/view/1936

#include <bits/stdc++.h>
#define max 100003
typedef unsigned long long llu;

using namespace std;

        int dp[max];
        int vetor[max];
        int n;

void fato( int stop ){
        vetor[0] = 0;
        vetor[1] = 1;
        vetor[2] = 2;
        for( int i=3; vetor[i-1] < stop ; i++ ){
                vetor[i] = vetor[i-1]*i;
        }
}
llu bu( int n){
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for( int i=3; i<=n; i++){
                dp[i] = INT_MAX;
                for(int j=1; vetor[j] <= i; j++){
                dp[i] = min( dp[i], dp[i-vetor[j]] + 1);
                }
        }
return dp[n];
}
void print() {
        for(int i =0; i < n; i++)
                cout << dp[i] <<  ' ';
        cout << endl;
}
int main() {
        cin >> n;
        fato(n+2);
        llu resp = bu( n );
        cout << resp << endl;
return 0;
}
