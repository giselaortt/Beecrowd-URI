#URL: beecrowd.com.br/judge/en/problems/view/1136

#include <bits/stdc++.h>
#define REP(a, b, c, d) for(int a = b; a < c; a += d)
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
#define mod( a ) a >= 0 ? a : -a
#define N 91
#define inf INT_MAX

using namespace std;

int subset[N];

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	bool good;

	while( A != 0 && B != 0 ){
		//memset(subset, 0, sizeof subset);
		REP(i, 0, B, 1) scanf("%d", &subset[i] );

		for(int i=1; i<=A; i++){
			good = false;
			for(int j=0; j<B; j++){
				for(int k=j+1; k<B; k++){
					if( subset[j] - subset[k] == i || -subset[j] + subset[k] == i ){ good = true; }
				}
				//if( good == true ) break;
			}
			if( good == false ) break;
		}
		if( good == false ) printf("N\n");
		else printf("Y\n");
		scanf("%d %d", &A, &B);
	}

return 0;
}
