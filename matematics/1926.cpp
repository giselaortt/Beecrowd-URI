#URL: https://www.beecrowd.com.br/judge/en/problems/view/1926

#include <bits/stdc++.h>
#define REP( a, b, c ) for(int a=b; a<c; a++)
#define inf INT_MAX
#define MAX 1000001
#define MAXS 1001
#define mod(a) a > 0 ? a : -a
#define min(a, b) a < b ? a : b

using namespace std;

bool primos[MAX];
int twins[MAX];

void crivo( ){
	for( int a=3; a<MAXS; a+=2 ){
		if( primos[a] == 0 )
			for(int j=a+a; j<MAX; j+= a) primos[j] = 1;
	}
	for(int i=3; i<MAX; i+=2){
		twins[i] = twins[i-2];
		twins[i-1] = twins[i-2];
		if( !primos[i] )
			if( !primos[i+2] || !primos[i-2] )   twins[i]++;
	}
}

int main(){
	crivo();
	int cases, a, b;
	scanf("%d", &cases);
	REP(i, 0, cases){
		scanf("%d %d", &a, &b);
		if(b > a )printf("%d\n", twins[b] - twins[a-1]);
		else printf("%d\n", twins[a] - twins[b-1]);
	}

	
return 0;
}
