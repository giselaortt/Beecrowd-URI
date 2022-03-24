#URL: https://www.beecrowd.com.br/judge/en/problems/view/c


#include <bits/stdc++.h>
#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
#define N 3002
#define inf 100000002

using namespace std;

typedef struct point{
	int x, y;
} point;

bool ord( point a, point b ){
	if( a.x != b.x ) return a.x < b.x;
	return a.y < b.y;
}

point vetor[N];

int main(){
	int num;
	scanf("%d", &num);
	for( int i=0; i<num; i++ ) scanf("%d %d", &vetor[i].x, &vetor[i].y);
	sort( vetor, vetor + num , ord);
	int ans = 0, ydown, yup;
	for( int i=0; i<num; i++ ){
		ydown = -inf; yup = inf;
		for( int j=i+1; j<num; j++ ){
			if( vetor[j].y > vetor[i].y && vetor[j].y < yup  ){ yup  = vetor[j].y; ans++; }
			else if( vetor[j].y < vetor[i].y && vetor[j].y > ydown ){ ydown = vetor[j].y; ans++; }
		}
	}
	printf("%d\n", ans);
return 0;
}
