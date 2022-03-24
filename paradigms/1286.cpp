#URL: https://www.beecrowd.com.br/judge/en/problems/view/1286

#include <bits/stdc++.h>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
#define N 21
#define M 31

using namespace std;

typedef struct item{
	int weight, value;
} item;

item vetor[N];

int dp[21][31];
int best( int items, int cap ){
	for( int i=1; i<=items; i++ )
		for( int j=1; j<=cap; j++ ){		
			if( vetor[i].weight > j ) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max( dp[i-1][j], dp[i-1][ j - vetor[i].weight ] + vetor[i].value );
		}
return dp[items][cap];
}

int main(){
	int n, cap;
	scanf("%d", &n );

	while( n != 0 ){
		scanf("%d", &cap );
		memset( vetor, 0, sizeof vetor );
		memset( dp, 0, sizeof dp );
		for(int i=1; i<=n; i++) scanf("%d %d", &vetor[i].value, &vetor[i].weight);
		printf("%d min.\n", best(n, cap));
		scanf("%d", &n );
	}

return 0;
}
